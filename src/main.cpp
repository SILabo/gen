/**
 * File Name   : message_parser_json.hpp
 * Auther      : Shinji Ikuta
 * Copyright   : © 2020 Artiza Networks, Inc.
 * Description :
 * Email       : ikuta_shinji@artiza.co.jp
 */

#include "RawData.hpp"
#include "GenQueue.hpp"
#include "sched.h"
#include "unistd.h"
#include "zmq.hpp"

namespace
{
    std::sig_atomic_t genSignalStatus;
}

namespace
{
#if 0
    using cmsg = std::vector<char*>;

    std::queue<RawData*> mpq1;
    std::queue<RawData*> mpq2;
    std::queue<RawData*> mpq3;
    std::queue<RawData*> mpq4;
    std::queue<RawData*> mpq5;

    std::queue<cmsg> pcq1;
    std::queue<cmsg> pcq2;
    std::queue<cmsg> pcq3;
    std::queue<cmsg> pcq4;

    std::mutex mu;
#endif
}

void genSignalHandler(int signal)
{
    genSignalStatus = signal;
}


void MsgThread(RawData* raw, GenQueue* gq)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    //Filtering Imformation
    std::cout << "---Filter Imfomation---" << std::endl;
    std::cout << "Layer2 tag : " << raw->filters->l2.tag << std::endl;
    std::cout << "Layer2 vlan_tags.tpid : " << raw->filters->l2.vlan_tags.tpid << std::endl;
    std::cout << "Layer2 vlan_tags.vid.start : " << raw->filters->l2.vlan_tags.vid->start << std::endl;
    std::cout << "Layer2 vlan_tags.vid.end : " << raw->filters->l2.vlan_tags.vid->end << std::endl;

    std::cout << "Layer3 tag : " << raw->filters->l3.tag << std::endl;
    std::cout << "Layer3 ipv4.src_addr : " << raw->filters->l3.ipv4.src_addr << std::endl;
    std::cout << "Layer3 ipv4.dst_addr : " << raw->filters->l3.ipv4.dst_addr << std::endl;
    std::cout << "Layer3 ipv6.src_addr : " << raw->filters->l3.ipv6.src_addr << std::endl;
    std::cout << "Layer3 ipv6.dst_addr : " << raw->filters->l3.ipv6.dst_addr << std::endl;

    std::cout << "Layer4 tag : " << raw->filters->l4.tag << std::endl;
    std::cout << "Layer4 ipv4.udp_src_port : " << raw->filters->l4.udp_src_port << std::endl;
    std::cout << "Layer4 ipv4.udp_dst_port : " << raw->filters->l4.udp_dst_port << std::endl;
    std::cout << "Layer4 ipv4.tcp_src_port : " << raw->filters->l4.tcp_src_port << std::endl;
    std::cout << "Layer4 ipv4.tcp_dst_port : " << raw->filters->l4.tcp_dst_port << std::endl;
    std::cout << "Layer4 ipv4.sctp_src_port : " << raw->filters->l4.sctp_src_port << std::endl;
    std::cout << "Layer4 ipv4.sctp_dst_port : " << raw->filters->l4.sctp_dst_port << std::endl;

    std::cout << "User ID : " << raw->user_id << std::endl;
    raw->capture_ids->at(0).SetPid(1);
    raw->capture_ids->at(0).SetCid(1539);
    std::cout << "Port ID : " << raw->capture_ids->at(0).GetPid() << std::endl;
    std::cout << "Capture ID : " << raw->capture_ids->at(0).GetCid() << std::endl;

    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REP);
    zmq::socket_t s(context, ZMQ_REQ);
    socket.bind("tcp://*:5555");
   
#if 1
    while (1)
    {
        MessageHeader* msg;
        //Waiting messsage
        zmq::message_t recv(20);
        socket.recv(&recv);
        msg = (MessageHeader*)recv.data();

        std::printf("message_id:0x%x\n", msg->message_id);
        std::printf("src_id:0x%x\n", msg->src_id);
        std::printf("dst_id:0x%x\n", msg->dst_id);
        std::printf("seq_no:0x%x\n", msg->seq_no);
        std::printf("ver_no:%d\n", msg->ver_no);

        // Do some 'work'
        std::chrono::milliseconds dura(1);
        std::this_thread::sleep_for(dura);    // 1 ミリ秒

        // Send reply back to client
        //zmq::message_t reply(10);
        //memcpy((void*)reply.data(), "Recv OK!", 10);
        //s.send(reply);
#endif

        //受信メッセージがあった場合、RawDataファイルをポート毎に振り分ける
        //時刻順にソートされたCaptureIDをvectorオブジェクトへ取り込む

        gq->mu.lock();
        gq->mpq1.push(raw);
        gq->mu.unlock();
        std::cout << "Port1Thread Send Queue： " << raw << std::endl;

        gq->mu.lock();
        gq->mpq2.push(raw);
        gq->mu.unlock();
        std::cout << "Port2Thread Send Queue： " << raw << std::endl;

        gq->mu.lock();
        gq->mpq3.push(raw);
        gq->mu.unlock();
        std::cout << "Port3Thread Send Queue： " << raw << std::endl;

        gq->mu.lock();
        gq->mpq4.push(raw);
        gq->mu.unlock();
        std::cout << "Port4Thread Send Queue： " << raw << std::endl;

        gq->mu.lock();
        gq->mpq5.push(raw);
        gq->mu.unlock();
        std::cout << "PcapThread Send Queue： " << raw << std::endl;

        //完了フラグ待ち
        //std::cout << "完了フラグ待ち　from PcapThread" << std::endl;
        //while (1)
        //{
            //Recv Queue Monitoring
            gq->mu.lock();
            if (gq->mpq1.size())
            {
                std::cout << "Pcap Generate Complete!!" << std::endl;
                std::cout << "MsgThread Recv Queue： " << gq->mpq1.front() << std::endl;
                gq->mpq1.pop();
                gq->mu.unlock();
                break;
            }
            gq->mu.unlock();
        //}

    }
    genSignalStatus = 0;
}

void PortThread(RawData* raw, GenQueue* gq)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    PortClass port;

    std::mutex iomutex;
    std::lock_guard<std::mutex> iolock(iomutex);
    std::cout << "Thread #" << std::this_thread::get_id() << ": on CPU " << sched_getcpu() << "\n";
    while(1)
    {
        //PORT1 recv queue monitoring
        gq->mu.lock();
        if (gq->mpq1.size())
        {
            std::cout << "Port1Thread Recv Queue： " << gq->mpq1.front() << std::endl;
            gq->mpq1.pop();
        }
        gq->mu.unlock();

        //PORT2 recv queue monitoring
        gq->mu.lock();
        if (gq->mpq2.size())
        {
            std::mutex iomutex;
            std::lock_guard<std::mutex> iolock(iomutex);
            std::cout << "Port2Thread Recv Queue： " << gq->mpq2.front() << std::endl;
            gq->mpq2.pop();
        }
        gq->mu.unlock();

        //PORT3 recv queue monitoring
        gq->mu.lock();
        if (gq->mpq3.size())
        {
            std::mutex iomutex;
            std::lock_guard<std::mutex> iolock(iomutex);
            std::cout << "Port3Thread Recv Queue： " << gq->mpq3.front() << std::endl;
            gq->mpq3.pop();
        }
        gq->mu.unlock();

        //PORT4 recv queue monitoring
        gq->mu.lock();
        if (gq->mpq4.size())
        {
            std::mutex iomutex;
            std::lock_guard<std::mutex> iolock(iomutex);
            std::cout << "Port4Thread Recv Queue： " << gq->mpq4.front() << std::endl;
            gq->mpq4.pop();
        }
        gq->mu.unlock();

        //ここからパケットデータの走査（フィルタリング含む）
        //RawDataオブジェクト内のvectorプジェクトのCaptureIDからファイルフルパスを得て
        //ファイルオープン／リードする。


    }
}

void PcapThread(RawData* raw, GenQueue* gq)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    while (1)
    {
        gq->mu.lock();
        //受信キュー待ち
        if (gq->mpq5.size())
        {
            std::mutex iomutex;
            std::lock_guard<std::mutex> iolock(iomutex);
            std::cout << "PcapThread Recv Queue： " << gq->mpq5.front() << std::endl;
            gq->mpq5.pop();
        }
        gq->mu.unlock();


    }
}

std::tuple<int> CreateThread(void (*func)(RawData* raw, GenQueue* gq), int cpuid, RawData* raw, GenQueue* gq)
{

    std::thread thread(func, raw, gq);

    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(cpuid, &cpuset);
    int rc = pthread_setaffinity_np(thread.native_handle(), sizeof(cpu_set_t), &cpuset);

    std::mutex iomutex;
    std::lock_guard<std::mutex> iolock(iomutex);
    std::cout << "Thread #" << cpuid << ": on CPU " << sched_getcpu() << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    return std::forward_as_tuple(rc);
}

int main(int argc, char* argv[])
{
    try {

        //RawData生成
        RawData* raw = new RawData(100);
        //GenQueue生成
        GenQueue* gq = new GenQueue();

        std::signal(SIGUSR1, genSignalHandler);

        unsigned num_cpus = std::thread::hardware_concurrency();
        std::cout << "Launching " << num_cpus << " threads\n";

        //Port1 Thread
        std::thread t1(PortThread, raw, gq);

        //SetAffinity
        int rc;
        cpu_set_t cpuset;
        CPU_ZERO(&cpuset);
        CPU_SET(1, &cpuset);
        rc = pthread_setaffinity_np(t1.native_handle(), sizeof(cpu_set_t), &cpuset);
        if (rc != 0) {
            std::cout << "Failure CPU1 rc=" << rc << " threads\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        //Port2 Thread
        std::thread t2(PortThread, raw, gq);
        //SetAffinity
        CPU_ZERO(&cpuset);
        CPU_SET(2, &cpuset);
        rc = pthread_setaffinity_np(t2.native_handle(), sizeof(cpu_set_t), &cpuset);
        if (rc != 0) {
            std::cout << "Failure CPU2 rc=" << rc << " threads\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        //Port3 Thread
        std::thread t3(PortThread, raw, gq);
        CPU_ZERO(&cpuset);
        CPU_SET(3, &cpuset);
        rc = pthread_setaffinity_np(t3.native_handle(), sizeof(cpu_set_t), &cpuset);
        if (rc != 0) {
            std::cout << "Failure CPU3 rc=" << rc << " threads\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        //Port4 Thread
        std::thread t4(PortThread, raw, gq);
        CPU_ZERO(&cpuset);
        CPU_SET(4, &cpuset);
        rc = pthread_setaffinity_np(t4.native_handle(), sizeof(cpu_set_t), &cpuset);
        if (rc != 0)
            std::cout << "Failure CPU4 rc=" << rc << " threads\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        //PCAP Thread
        std::thread t5(PcapThread, raw, gq);
        CPU_ZERO(&cpuset);
        CPU_SET(5, &cpuset);
        rc = pthread_setaffinity_np(t5.native_handle(), sizeof(cpu_set_t), &cpuset);
        if (rc != 0)
            std::cout << "Failure CPU5 rc=" << rc << " threads\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        
        
        MsgThread(raw, gq);

        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();

    }
    catch (std::exception & ex) {
        std::cerr << ex.what() << std::endl;
    }
    return (0);
}
