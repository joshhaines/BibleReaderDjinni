//
//  br_base_record.hpp
//  BibleReaderCPP
//
//  Created by Joshua Haines on 5/15/16.
//  Copyright © 2016 Joshua Haines. All rights reserved.
//

#ifndef br_base_record_hpp
#define br_base_record_hpp

#include <stdio.h>
#include "br_base_record_base.hpp"

namespace biblereader {
    class BrBaseRecord : public BrBaseRecordBase {
    public:
        using BrBaseRecordBase::BrBaseRecordBase;
        
        BrBaseRecord();
    };
}

#endif /* br_base_record_hpp */
