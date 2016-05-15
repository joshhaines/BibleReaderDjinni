//
//  br_network_manager_impl.cpp
//  BibleReaderCPP
//
//  Created by Joshua Haines on 5/13/16.
//  Copyright © 2016 Joshua Haines. All rights reserved.
//

#include "br_network_manager_impl.hpp"
#include <curl/curl.h>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread.hpp>


boost::mutex global_stream_lock;

void WorkerThread( boost::shared_ptr< boost::asio::io_service > io_service )
{
    global_stream_lock.lock();
    std::cout << "[" << boost::this_thread::get_id()
    << "] Thread Start" << std::endl;
    global_stream_lock.unlock();
    
    while( true )
    {
        try
        {
            boost::system::error_code ec;
            io_service->run( ec );
            if( ec )
            {
                global_stream_lock.lock();
                std::cout << "[" << boost::this_thread::get_id()
                << "] Error: " << ec << std::endl;
                global_stream_lock.unlock();
            }
            break;
        }
        catch( std::exception & ex )
        {
            global_stream_lock.lock();
            std::cout << "[" << boost::this_thread::get_id()
            << "] Exception: " << ex.what() << std::endl;
            global_stream_lock.unlock();
        }
    }
    
    global_stream_lock.lock();
    std::cout << "[" << boost::this_thread::get_id()
    << "] Thread Finish" << std::endl;
    global_stream_lock.unlock();
}

std::shared_ptr<biblereader::BrNetworkManager> biblereader::BrNetworkManager::create() {
    return std::make_shared<biblereader::BrNetworkManagerImpl>();
}

size_t writeCallback(char* buf, size_t size, size_t nmemb, void *up) {
    for (int c = 0; c < size*nmemb; c++) {
        ((std::string*)up)->push_back(buf[c]);
    }
    return size*nmemb;
}

void thread_get_bible_books(std::string *data, const std::shared_ptr<biblereader::BrNetworkListener> &listener) {
    
    std::unique_ptr<CURL, void(*)(CURL*)> curl(
        curl_easy_init(), &curl_easy_cleanup
    );
//    std::shared_ptr<CURL> blabla(
//        curl_easy_init(), &curl_easy_cleanup
//    );
//    boost::shared_ptr<CURL> curl(
//                                 curl_easy_init(), &curl_easy_cleanup
//                                 );
    
    curl_global_init(CURL_GLOBAL_ALL);
    
    curl_easy_setopt(curl.get(), CURLOPT_URL, "https://bibles.org/v2/verses/eng-GNTD:Acts.8.34.xml");
    curl_easy_setopt(curl.get(), CURLOPT_USERPWD, "WcBbphrvgP22kmgZwaCFtGeuBvZGXzf7xtPPallq:X");
    curl_easy_setopt(curl.get(), CURLOPT_WRITEFUNCTION, &writeCallback);
    curl_easy_setopt(curl.get(), CURLOPT_WRITEDATA, data);
    curl_easy_setopt(curl.get(), CURLOPT_FOLLOWLOCATION, 1L);
    
    curl_easy_perform(curl.get());
    
    curl_global_cleanup();
    
    if (listener) {
        listener->complete();
    }
}

std::vector<std::string> biblereader::BrNetworkManagerImpl::get_bible_books(const std::shared_ptr<biblereader::BrNetworkListener> &listener) {
    
    std::string data;
    boost::thread t{ boost::bind( &thread_get_bible_books, &data, listener) };
    t.join();
    
    std::cout << std::endl << data << std::endl;
    //    cin.get();
    
    return std::vector<std::string>();
}