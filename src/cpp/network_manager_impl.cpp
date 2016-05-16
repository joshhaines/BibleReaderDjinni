//
//  network_manager_impl.cpp
//  BibleReaderCPP
//
//  Created by Joshua Haines on 5/13/16.
//  Copyright © 2016 Joshua Haines. All rights reserved.
//

#include "network_manager_impl.hpp"
#include <curl/curl.h>
#include <iostream>
#include <future>
#include "base_view_model_impl.hpp"

using namespace biblereader;

std::shared_ptr<NetworkManager> NetworkManager::create() {
    return std::make_shared<NetworkManagerImpl>();
}

NetworkManagerImpl::NetworkManagerImpl() {
    
}

size_t writeCallback(char* buf, size_t size, size_t nmemb, void *up) {
    for (int c = 0; c < size*nmemb; c++) {
        ((std::string*)up)->push_back(buf[c]);
    }
    return size*nmemb;
}

void NetworkManagerImpl::get_bible_books(const std::shared_ptr<NetworkListener> &listener) {
    
    std::string data;
    
    std::cout << "Starting fetch for bible books" << std::endl;
    
    std::shared_ptr<BaseViewModelImpl> vm(
                                                         new BaseViewModelImpl()
                                                         );
    
    auto handle = std::async(std::launch::async, [&listener, &data, vm](){
        std::unique_ptr<CURL, void(*)(CURL*)> curl(
                                                   curl_easy_init(), &curl_easy_cleanup
                                                   );
        
        curl_global_init(CURL_GLOBAL_ALL);
        
        curl_easy_setopt(curl.get(), CURLOPT_URL, "https://bibles.org/v2/verses/eng-GNTD:Acts.8.34.xml");
        curl_easy_setopt(curl.get(), CURLOPT_USERPWD, "WcBbphrvgP22kmgZwaCFtGeuBvZGXzf7xtPPallq:X");
        curl_easy_setopt(curl.get(), CURLOPT_WRITEFUNCTION, &writeCallback);
        curl_easy_setopt(curl.get(), CURLOPT_WRITEDATA, &data);
        curl_easy_setopt(curl.get(), CURLOPT_FOLLOWLOCATION, 1L);
        
        curl_easy_perform(curl.get());
        
        curl_global_cleanup();
        
        std::cout << data << std::endl;
        
        vm->set_xml(data);
        
        if (listener) {
            listener->complete(NULL);
        }
    });
    
    return;
}