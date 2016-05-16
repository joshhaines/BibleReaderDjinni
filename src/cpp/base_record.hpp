//
//  base_record.hpp
//  BibleReaderCPP
//
//  Created by Joshua Haines on 5/15/16.
//  Copyright © 2016 Joshua Haines. All rights reserved.
//

#ifndef base_record_hpp
#define base_record_hpp

#include <stdio.h>
#include "base_record_base.hpp"

namespace biblereader {
    struct BaseRecord : public BaseRecordBase {
    public:
        using BaseRecordBase::BaseRecordBase;
        
        BaseRecord();
    };
}

#endif /* base_record_hpp */
