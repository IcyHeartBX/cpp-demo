> Log4cplus 笔记

参考：http://blog.csdn.net/gatieme/article/details/50603682

# 一、安装

下载源代码包，[http://sourceforge.net/projects/log4cplus/](http://sourceforge.net/projects/log4cplus/)

```shell
tar jxvf log4cplus-1.2.1-rc2.tar.xz
```

安装

```shell
./configure --prefix=/usr/local/install
make
make install
```



# 二、使用

引入动态库和包含头文件，都在/usr/local/install/lib  /usr/local/install/include

参考：http://blog.csdn.net/lx_shudong/article/details/48732999



# 三、封装

Demo:https://github.com/IcyHeartBX/CppLog4cplusX

```Cpp
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
    static void init() {
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
```





