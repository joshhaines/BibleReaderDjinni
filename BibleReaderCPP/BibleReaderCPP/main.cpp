//
//  main.cpp
//  BibleReaderCPP
//
//  Created by Joshua Haines on 5/13/16.
//  Copyright © 2016 Joshua Haines. All rights reserved.
//

#include <iostream>
#include "br_network_manager_impl.hpp"
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>

using namespace biblereader;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    boost::shared_ptr<BrNetworkManagerImpl> networkManager(
        new BrNetworkManagerImpl
    );
    
    std::shared_ptr<BrNetworkListener> listener;
    
    networkManager->get_bible_books(NULL);
    
    //    boost::asio::io_service io_service;
    //    boost::asio::io_service::work work( networkManager.get_bible_books() );
    //
    //    io_service.run();
    
//    std::cin.get();
    std::cout << "bla bla" << std::endl;
    
    return 0;
}
