//
//  file1.h
//  CppLog4cppX
//
//  Created by PixBoly on 2018/1/28.
//  Copyright © 2018年 pix. All rights reserved.
//

#ifndef file1_h
#define file1_h

#include "LogUtil.h"
void file1main() {
    LOG4CPLUS_DEBUG(LogUtils::GetLogger(), "flie1main()"<<",RUN...");
}
#endif /* file1_h */
