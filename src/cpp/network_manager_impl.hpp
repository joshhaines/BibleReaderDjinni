//
//  br_network_manager_impl.hpp
//  BibleReaderCPP
//
//  Created by Joshua Haines on 5/13/16.
//  Copyright © 2016 Joshua Haines. All rights reserved.
//

#ifndef network_manager_impl_hpp
#define network_manager_impl_hpp

#include <stdio.h>
#include "network_manager.hpp"
#include "network_listener.hpp"

namespace biblereader {
    class NetworkManagerImpl : public NetworkManager {
        
    public:
        NetworkManagerImpl();
        
        void get_bible_books(const std::shared_ptr<NetworkListener> & listener);
        
    };
}

#endif /* network_manager_impl_hpp */
