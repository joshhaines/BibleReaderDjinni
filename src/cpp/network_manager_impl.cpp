//
//  network_manager_impl.cpp
//  BibleReaderCPP
//
//  Created by Joshua Haines on 5/13/16.
//  Copyright © 2016 Joshua Haines. All rights reserved.
//

#define BOOST_NETWORK_ENABLE_HTTPS

#include "network_manager_impl.hpp"
//#include <curl/curl.h>
#include <iostream>
#include <future>
#include "base_view_model_impl.hpp"
#include <boost/network/protocol/http/client.hpp>
#include "base64.hpp"
#include <boost/system/error_code.hpp>

using namespace biblereader;
using namespace boost::network;
using namespace boost::network::http;

std::shared_ptr<NetworkManager> NetworkManager::create() {
    return std::make_shared<NetworkManagerImpl>();
}

NetworkManagerImpl::NetworkManagerImpl() {
    
}

//size_t writeCallback(char* buf, size_t size, size_t nmemb, void *up) {
//    for (int c = 0; c < size*nmemb; c++) {
//        ((std::string*)up)->push_back(buf[c]);
//    }
//    return size*nmemb;
//}
//
//BOOST_NETWORK_HTTP_BODY_CALLBACK(print_body, range, error) {
//    if (!error) {
//        std::cout << "callback" << std::endl;
//    } else {
//        std::cout << "error" << std::endl;
//    }
//}
//
//void blabla(boost::iterator_range<char const *> const & a, std::error_code const & b) {
//    std::cout << "hahaha" << std::endl;
//}

void NetworkManagerImpl::get_bible_books(const std::shared_ptr<NetworkListener> &listener) {
    
//    std::string data;
//    
//    std::cout << "Starting fetch for bible books" << std::endl;
//    
//    std::shared_ptr<BaseViewModelImpl> vm(
//                                                         new BaseViewModelImpl()
//                                                         );
    
    auto handle = std::async(std::launch::async, [&listener](){
        const std::string key = "WcBbphrvgP22kmgZwaCFtGeuBvZGXzf7xtPPallq:X";
        std::string encoded = base64_encode(reinterpret_cast<const unsigned char*>(key.c_str()), (unsigned int) key.length());
        client::request request_("https://bibles.org/v2/verses/eng-GNTD:Acts.8.34.xml");
        request_ << header("Connection", "close");
        std::string header_ = "Basic " + encoded;
        request_ << header("Authorization", header_);
        client::options options;
        options.follow_redirects(true);
        //    options.always_verify_peer(false);
        client client_(options);
        try {
            std::string body_string;
            client::response response_ = client_.get(request_);
                    std::string body_ = body(response_);
                    std::cout << body_ << std::endl;
        } catch (std::exception & e) {
            std::cerr << e.what() << std::endl;
        }
        
        
        
//        std::unique_ptr<CURL, void(*)(CURL*)> curl(
//                                                   curl_easy_init(), &curl_easy_cleanup
//                                                   );
//        
//        curl_global_init(CURL_GLOBAL_ALL);
//        
//        curl_easy_setopt(curl.get(), CURLOPT_URL, "https://bibles.org/v2/verses/eng-GNTD:Acts.8.34.xml");
//        curl_easy_setopt(curl.get(), CURLOPT_USERPWD, "WcBbphrvgP22kmgZwaCFtGeuBvZGXzf7xtPPallq:X");
//        curl_easy_setopt(curl.get(), CURLOPT_WRITEFUNCTION, &writeCallback);
//        curl_easy_setopt(curl.get(), CURLOPT_WRITEDATA, &data);
//        curl_easy_setopt(curl.get(), CURLOPT_FOLLOWLOCATION, 1L);
//        
//        curl_easy_perform(curl.get());
//        
//        curl_global_cleanup();
//        
//        std::cout << data << std::endl;
//        
//        vm->set_xml(data);
        
        if (listener) {
            listener->complete(NULL);
        }
    });
    
    return;
}