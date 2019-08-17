//
//  LogUtil.h
//  CppLog4cppX
//
//  Created by PixBoly on 2018/1/28.
//  Copyright © 2018年 pix. All rights reserved.
//

#ifndef LogUtil_h
#define LogUtil_h
#include <log4cplus/logger.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/layout.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/loggingmacros.h>
#include <iostream>

using namespace log4cplus;
using namespace log4cplus::helpers;

class LogUtils {
public:
    static void init(std::string log_file) {
        SharedObjectPtr<Appender> _append (new ConsoleAppender());
        _append->setName("append for  test");
        
        /* step 2: Instantiate a layout object */
        std::string pattern = "%d{%y-%m-%d  %H:%M:%S}  - %m [%l]%n";
        std::auto_ptr<Layout> _layout(new PatternLayout(pattern));
        
        /* step 3: Attach the layout object to the appender */
        _append->setLayout( _layout );
        /* step 4:  Instantiate a logger object */
        static Logger _logger = Logger::getInstance("test");
        pLog = &_logger;
        
        // 增加一个写文件按文件大小写
        // SharedAppenderPtr _append1(new RollingFileAppender("/Users/tangpengxiang/Downloads/Test.log", 5*1024, 5));
        //_append1->setName("file test");
        //_append1->setLayout(std::auto_ptr<Layout>(new TTCCLayout()));
        //_logger.addAppender(_append1);
        // 按日期写
        SharedAppenderPtr _appendf(new DailyRollingFileAppender(log_file, DAILY, false, 100));
        _appendf->setName("file test");
        _appendf->setLayout(std::auto_ptr<Layout>(new PatternLayout(pattern)));
        _logger.addAppender(_appendf);
        /* step 5: Attach the appender object to the  logger  */
        _logger.addAppender(_append);
        /* step 6: Set a priority for the logger  */
        _logger.setLogLevel(ALL_LOG_LEVEL);
    }
    static Logger & GetLogger() {
        return *pLog;
    }
private:
    static Logger * pLog;
};

Logger * LogUtils::pLog = NULL;

#endif /* LogUtil_h */
