//
//  base_view_model_impl.cpp
//  BibleReaderCPP
//
//  Created by Joshua Haines on 5/15/16.
//  Copyright © 2016 Joshua Haines. All rights reserved.
//

#include "base_view_model_impl.hpp"

using namespace biblereader;

std::shared_ptr<BaseViewModel> BaseViewModel::create() {
    return std::make_shared<BaseViewModelImpl>();
}

BaseViewModelImpl::BaseViewModelImpl() {
    viewModel = std::make_shared<BaseRecord>();
}

void BaseViewModelImpl::set_xml(const std::string & xml) {
    viewModel->xml = xml;
}

std::string BaseViewModelImpl::get_xml() {
    return viewModel->xml;
}