//
//  br_base_view_model_impl.cpp
//  BibleReaderCPP
//
//  Created by Joshua Haines on 5/15/16.
//  Copyright © 2016 Joshua Haines. All rights reserved.
//

#include "br_base_view_model_impl.hpp"

static std::shared_ptr<biblereader::BrBaseViewModel> create() {
    return std::make_shared<biblereader::BrBaseViewModelImpl>();
}

biblereader::BrBaseViewModelImpl::BrBaseViewModelImpl() {
    
}