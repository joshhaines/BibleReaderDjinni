//
//  base_view_model_impl.hpp
//  BibleReaderCPP
//
//  Created by Joshua Haines on 5/15/16.
//  Copyright © 2016 Joshua Haines. All rights reserved.
//

#ifndef base_view_model_impl_hpp
#define base_view_model_impl_hpp

#include <stdio.h>
#include "base_view_model.hpp"
#include "base_record.hpp"

namespace biblereader {
    class BaseViewModelImpl : public BaseViewModel {
    public:
        BaseViewModelImpl();
        
        void set_xml(const std::string & xml);
    private:
        std::shared_ptr<BaseRecord> viewModel;
    };
}

#endif /* base_view_model_impl_hpp */
