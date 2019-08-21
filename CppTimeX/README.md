> c/c++ 时间笔记

# 一、[参考1：](http://www.runoob.com/cplusplus/cpp-date-time.html)

## 1、简介

C++ 标准库没有提供所谓的日期类型。C++ 继承了 C 语言用于日期和时间操作的结构和函数。为了使用日期和时间相关的函数和结构，需要在 C++ 程序中引用 <ctime> 头文件。

有四个与时间相关的类型：**clock_t、time_t、size_t** 和 **tm**。类型 clock_t、size_t 和 time_t 能够把系统时间和日期表示为某种整数。



## 2、tm结构体

结构类型 **tm** 把日期和时间以 C 结构的形式保存，tm 结构的定义如下：

```c
struct tm {
  int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
  int tm_min;   // 分，范围从 0 到 59
  int tm_hour;  // 小时，范围从 0 到 23
  int tm_mday;  // 一月中的第几天，范围从 1 到 31
  int tm_mon;   // 月，范围从 0 到 11
  int tm_year;  // 自 1900 年起的年数
  int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
  int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
  int tm_isdst; // 夏令时
}
```

下面是 C/C++ 中关于日期和时间的重要函数。所有这些函数都是 C/C++ 标准库的组成部分，您可以在 C++ 标准库中查看一下各个函数的细节。

。

| 序号   | 函数 & 描述                                  |
| ---- | ---------------------------------------- |
| 1    | [**time_t time(time_t \*time);**](http://www.runoob.com/cplusplus/c-function-time.html)该函数返回系统的当前日历时间，自 1970 年 1 月 1 日以来经过的秒数。如果系统没有时间，则返回 .1。 |
| 2    | [**char \*ctime(const time_t *time);**](http://www.runoob.com/cplusplus/c-function-ctime.html)该返回一个表示当地时间的字符串指针，字符串形式 *day month year hours:minutes:seconds year\n\0*。 |
| 3    | [**struct tm \*localtime(const time_t *time);**](http://www.runoob.com/cplusplus/c-function-localtime.html)该函数返回一个指向表示本地时间的 **tm** 结构的指针。 |
| 4    | [**clock_t clock(void);**](http://www.runoob.com/cplusplus/c-function-clock.html)该函数返回程序执行起（一般为程序的开头），处理器时钟所使用的时间。如果时间不可用，则返回 .1。 |
| 5    | [**char \* asctime ( const struct tm * time );**](http://www.runoob.com/cplusplus/c-function-asctime.html)该函数返回一个指向字符串的指针，字符串包含了 time 所指向结构中存储的信息，返回形式为：day month date hours:minutes:seconds year\n\0。 |
| 6    | [**struct tm \*gmtime(const time_t *time);**](http://www.runoob.com/cplusplus/c-function-gmtime.html)该函数返回一个指向 time 的指针，time 为 tm 结构，用协调世界时（UTC）也被称为格林尼治标准时间（GMT）表示。 |
| 7    | [**time_t mktime(struct tm \*time);**](http://www.runoob.com/cplusplus/c-function-mktime.html)该函数返回日历时间，相当于 time 所指向结构中存储的时间。 |
| 8    | [**double difftime ( time_t time2, time_t time1 );**](http://www.runoob.com/cplusplus/c-function-difftime.html)该函数返回 time1 和 time2 之间相差的秒数。 |
| 9    | [**size_t strftime();**](http://www.runoob.com/cplusplus/c-function-strftime.html)该函数可用于格式化日期和时间为指定的格式。 |

## 3、获取当前日期和时间

下面的实例获取当前系统的日期和时间，包括本地时间和协调世界时（UTC）。

```c
#include <iostream>
#include <ctime>
 
using namespace std;
 
int main( )
{
   // 基于当前系统的当前日期/时间
   time_t now = time(0);
   
   // 把 now 转换为字符串形式
   char* dt = ctime(&now);
 
   cout << "本地日期和时间：" << dt << endl;
 
   // 把 now 转换为 tm 结构
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "UTC 日期和时间："<< dt << endl;
}
```

```
本地日期和时间：Sat Jan  8 20:07:41 2011

UTC 日期和时间：Sun Jan  9 03:07:41 2011
```

## 4、使用结构 tm 格式化时间

**tm** 结构在 C/C++ 中处理日期和时间相关的操作时，显得尤为重要。tm 结构以 C 结构的形式保存日期和时间。大多数与时间相关的函数都使用了 tm 结构。下面的实例使用了 tm 结构和各种与日期和时间相关的函数。

在练习使用结构之前，需要对 C 结构有基本的了解，并懂得如何使用箭头 -> 运算符来访问结构成员。

```c
#include <iostream>
#include <ctime>
 
using namespace std;
 
int main( )
{
   // 基于当前系统的当前日期/时间
   time_t now = time(0);
 
   cout << "1970 到目前经过秒数:" << now << endl;
 
   tm *ltm = localtime(&now);
 
   // 输出 tm 结构的各个组成部分
   cout << "年: "<< 1900 + ltm->tm_year << endl;
   cout << "月: "<< 1 + ltm->tm_mon<< endl;
   cout << "日: "<<  ltm->tm_mday << endl;
   cout << "时间: "<< ltm->tm_hour << ":";
   cout << ltm->tm_min << ":";
   cout << ltm->tm_sec << endl;
}
```

```
1970 到目前时间:1503564157
年: 2017
月: 8
日: 24
时间: 16:42:37
```



# 二、[参考2](http://blog.csdn.net/code_robot/article/details/33305375)

C语言获取时间的相关函数，包括如果获取微妙、毫秒级时间

## 1、timeval结构体

timeval结构体定义在time.h中：

```c
struct timeval
{
     __time_t tv_sec;                /* Seconds. */
     __suseconds_t tv_usec;          /* Microseconds. */
};
```

其中，tv_sec为从1970-1-1零点零分到创建struct timeval时的秒数，tv_usec为微秒数。
注意：它是指从1970-1-1 0:0:0 零微秒至当前的时间差tv_sec秒后面的零头。所以，要想获取一个操作或子程序的运行毫秒或微秒级时长，不能简单实用前后两个时间采集点的tv_usec相减，否则会出现负值(如timeval_test_0.cpp)，而应考虑到前后两个时间点的秒差（tv_sec）（见timeval_test.cpp及其运行结果）。

## 2、与timeval相关的gettimeofday()函数 ：

该函数的注解为

```c
/* Get the current time of day and timezone information, 
   putting it into *TV and *TZ. If TZ is NULL, *TZ is not filled. 
   Returns 0 on success, -1 on errors. 
   NOTE: This form of timezone information is obsolete. 
   Use the functions and variables declared in <time.h> instead. */  
extern int gettimeofday (struct timeval *__restrict __tv,  
                         __timezone_ptr_t __tz) __THROW __nonnull ((1)); 
```

gettimeofday()功能是得到当前时间和时区，分别写到tv和tz中，如果tz为NULL则不向tz写入。

## 3、gmtime()函数

原 型：struct tm *gmtime(long *clock);

　　功 能：把日期和时间转换为格林威治(GMT)时间的函数。将参数timep 所指的time_t 结构中的信息转换成真实世界所使用的时间日期表示方法，然后将结果由结构tm返回。 

　　说 明：此函数返回的时间日期未经时区转换，而是UTC时间。

　　返回值：返回结构tm代表目前UTC 时间

## 4、localtime()函数

功 能: 把从1970-1-1零点零分到当前时间系统所偏移的秒数时间转换为日历时间 。

说 明：此函数获得的tm结构体的时间，是已经进行过时区转化为本地时间。

用 法: struct tm *localtime(const time_t *clock);

返回值：返回指向tm 结构体的指针.tm结构体是time.h中定义的用于分别存储时间的各个量(年月日等)

- localtime()和gmtime()的区别：

  ```c
  localtime()和gmtime()的区别：
  　　gmtime()函数功能类似获取当前系统时间，只是获取的时间未经过时区转换。
  　　localtime函数获得的tm结构体的时间，是已经进行过时区转化为本地时间。
  ```

- localtime_r()和gmtime_r()函数

  ```C
  　struct tm *gmtime_r(const time_t *timep, struct tm * sresult); 
  　struct tm *localtime_r(const time_t *timep, struct tm *result);
  　　gmtime_r()函数功能与此相同，但是它可以将数据存储到用户提供的结构体中。
  　　localtime_r()函数功能与此相同，但是它可以将数据存储到用户提供的结构体中。它不需要设置tzname。
  　　使用gmtime和localtime后要立即处理结果，否则返回的指针指向的内容可能会被覆盖。
  	一个好的方法是使用gmtime_r和localtime_r，由于使用了用户分配的内存，这两个函数是不会出错的。
  ```

## 5、asctime()函数

功 能: 转换日期和时间为相应的字符串（英文简写形式，形如：Mon Feb 16 11:29:26 2009）　　

用 法: char *asctime(const struct tm *tblock);

## 6、ctime()函数

功 能: 把日期和时间转换为字符串。（英文简写形式，形如：Mon Feb 16 11:29:26 2009）

用 法: char *ctime(const time_t *time);

说 明：ctime同asctime的区别在于，ctime是通过日历时间来生成时间字符串，
​                  而asctime是通过tm结构来生成时间字符串。

## 7、mktime()函数

功 能：将tm时间结构数据转换成经过的秒数（日历时间）。

原 型：time_t mktime(strcut tm * timeptr);。

说 明：mktime()用来将参数timeptr所指的tm结构数据转换成
​                   从公元1970年1月1日0时0分0 秒算起至今的UTC时间所经过的秒数。

返回值：返回经过的秒数。

## 8、difftime()函数

功 能：计算时间间隔才长度，以秒为单位，且只能精确到秒。

原 型：double difftime(time_t time1, time_t time0);

说 明：虽然该函数返回值是double类型的，但这并不说明该时间间隔具有同double一样的精度，
​                   这是由它的参数决定的。

## 9、strftime()函数

功 能：将时间格式化，或者说：格式化一个时间字符串。我们可以使用strftime()函数将时间格式化为我们想要的格式。

　　原 型：[size_t](http://baike.baidu.com/view/3236587.htm) strftime(char *strDest,size_t maxsize,const char *format,const struct tm *timeptr);

　　参 数：我们可以根据format指向字符串中格式命令把timeptr中保存的时间信息放在strDest指向的字符串中，
​                   最多向strDest中存放maxsize个字符。

　　返回值：该函数返回向strDest指向的字符串中放置的字符数。

　　类似于sprintf()：识别以百分号(%)开始的格式命令集合，格式化输出结果放在一个字符串中。
​                    格式化命令说明串strDest中各种日期和时间信息的确切表示方法。格式串中的其他字符原样放进串中。
​                    格式命令列在下面，它们是区分大小写的。

　　%a 星期几的简写

　　%A 星期几的全称

　　%b 月份的简写

　　%B 月份的全称

　　%c 标准的日期的时间串

　　%C 年份的后两位数字

　　%d 十进制表示的每月的第几天

　　%D 月/天/年

　　%e 在两字符域中，十进制表示的每月的第几天

　　%F 年-月-日

　　%g 年份的后两位数字，使用基于周的年

　　%G 年份，使用基于周的年

　　%h 简写的月份名

　　%H [24小时制](http://baike.baidu.com/view/4884834.htm)的小时

　　%I 12小时制的小时

　　%j 十进制表示的每年的第几天

　　%m 十进制表示的月份

　　%M 十时制表示的分钟数

　　%n 新行符

　　%p 本地的AM或PM的等价显示

　　%r 12小时的时间

　　%R 显示小时和分钟：hh:mm

　　%S 十进制的秒数

　　%t 水平制表符

　　%T 显示时分秒：hh:mm:ss

　　%u 每周的第几天，星期一为第一天 （值从0到6，星期一为0）

　　%U 第年的第几周，把星期日作为第一天（值从0到53）

　　%V 每年的第几周，使用基于周的年

　　%w 十进制表示的星期几（值从0到6，星期天为0）

　　%W 每年的第几周，把星期一做为第一天（值从0到53）

　　%x 标准的日期串

　　%X 标准的时间串

　　%y 不带世纪的十进制年份（值从0到99）

　　%Y 带世纪部分的十制年份

　　%z，%Z 时区名称，如果不能得到时区名称则返回空字符。

　　%% 百分号

　　提示：与 gmstrftime() 的行为相同，不同的是返回时间是本地时间。

