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
#include <future>
#include "br_base_view_model_impl.cpp"

std::shared_ptr<biblereader::BrNetworkManager> biblereader::BrNetworkManager::create() {
    return std::make_shared<biblereader::BrNetworkManagerImpl>();
}

size_t writeCallback(char* buf, size_t size, size_t nmemb, void *up) {
    for (int c = 0; c < size*nmemb; c++) {
        ((std::string*)up)->push_back(buf[c]);
    }
    return size*nmemb;
}

void biblereader::BrNetworkManagerImpl::get_bible_books(const std::shared_ptr<biblereader::BrNetworkListener> &listener) {
    
    std::string data;
    
    std::cout << "Starting fetch for bible books" << std::endl;
    
    std::shared_ptr<biblereader::BrBaseViewModel> vm = biblereader::BrBaseViewModelImpl::create();
    
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
        
        if (listener) {
            listener->complete(vm);
        }
    });
    
    return;
}