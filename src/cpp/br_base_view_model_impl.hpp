//
//  br_base_view_model_impl.hpp
//  BibleReaderCPP
//
//  Created by Joshua Haines on 5/15/16.
//  Copyright © 2016 Joshua Haines. All rights reserved.
//

#ifndef br_base_view_model_impl_hpp
#define br_base_view_model_impl_hpp

#include <stdio.h>
#include "br_base_view_model.hpp"
#include "br_base_record.hpp"

namespace biblereader {
    class BrBaseViewModelImpl : public BrBaseViewModel {
    public:
        BrBaseViewModelImpl();
        
        void set_xml(const std::string & xml);
    private:
        std::shared_ptr<BrBaseRecord> viewModel;
    };
}

#endif /* br_base_view_model_impl_hpp */
