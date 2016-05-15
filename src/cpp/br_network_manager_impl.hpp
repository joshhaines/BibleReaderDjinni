//
//  br_network_manager_impl.hpp
//  BibleReaderCPP
//
//  Created by Joshua Haines on 5/13/16.
//  Copyright © 2016 Joshua Haines. All rights reserved.
//

#ifndef br_network_manager_impl_hpp
#define br_network_manager_impl_hpp

#include <stdio.h>
#include "br_network_manager.hpp"
#include "br_network_listener.hpp"

namespace biblereader {
    class BrNetworkManagerImpl : public BrNetworkManager {
        
    public:
        void get_bible_books(const std::shared_ptr<BrNetworkListener> & listener);
        
    };
}

#endif /* br_network_manager_impl_hpp */
