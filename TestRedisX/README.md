> Redis笔记

# 一、简介

也是数据库，No-sql数据库

数据存在内存中，所以特别快！

## 操作文档



# 二、安装

## 1、Mac

参考：http://www.le.com/ptv/vplay/24159315.html

现在自己mac上安装一下，下载地址：[https://redis.io/download]

版本4.0.7:`redis-4.0.7.tar.gz`

解压

```shell
tar -zxvf redis-4.0.7.tar.gz
```

移动到安装目录

```shell
mv redis-4.0.7 /usr/local/install/
```

进入目录，make

```
cd /usr/local/install/redis-4.0.7
make
```

进入src目录

```shell
cd src
```

- redis-benchmark（压力测试工具）
- redis-check-aof（检测.aof文件完整性工具）
- redis-server(redis服务器程序)
- redis-cli(redis客户端程序)
- redis配置文件`redis.conf`

移动下面文件到新的目录

```shell
[tangpengxiang@bogon myredis]$pwd
/usr/local/myredis
[tangpengxiang@bogon myredis]$ls -l
total 7584
-rwxr-xr-x  1 root  wheel   105444  1 26 09:51 redis-benchmark
-rwxr-xr-x  1 root  wheel  1199668  1 26 09:51 redis-check-aof
-rwxr-xr-x  1 root  wheel  1199668  1 26 09:53 redis-check-rdb
-rwxr-xr-x  1 root  wheel   172760  1 26 09:52 redis-cli
-rwxr-xr-x  1 root  wheel  1199668  1 26 09:52 redis-server
-rw-r--r--  1 root  wheel    58353  1 26 09:56 redis.conf
-rwxr-xr-x  1 root  wheel      566  1 26 09:59 mkreleasehdr.sh
[tangpengxiang@bogon myredis]$
```

这里移动到`/usr/local/myredis`

- 启动

  ```shell
  ./redis-server redis.conf
  ```

```shell
[tangpengxiang@bogon myredis]$./redis-server redis.conf
36536:C 26 Jan 10:00:34.093 # oO0OoO0OoO0Oo Redis is starting oO0OoO0OoO0Oo
36536:C 26 Jan 10:00:34.093 # Redis version=4.0.7, bits=64, commit=00000000, modified=0, pid=36536, just started
36536:C 26 Jan 10:00:34.093 # Configuration loaded
36536:M 26 Jan 10:00:34.095 * Increased maximum number of open files to 10032 (it was originally set to 4864).
                _._
           _.-``__ ''-._
      _.-``    `.  `_.  ''-._           Redis 4.0.7 (00000000/0) 64 bit
  .-`` .-```.  ```\/    _.,_ ''-._
 (    '      ,       .-`  | `,    )     Running in standalone mode
 |`-._`-...-` __...-.``-._|'` _.-'|     Port: 6379
 |    `-._   `._    /     _.-'    |     PID: 36536
  `-._    `-._  `-./  _.-'    _.-'
 |`-._`-._    `-.__.-'    _.-'_.-'|
 |    `-._`-._        _.-'_.-'    |           http://redis.io
  `-._    `-._`-.__.-'_.-'    _.-'
 |`-._`-._    `-.__.-'    _.-'_.-'|
 |    `-._`-._        _.-'_.-'    |
  `-._    `-._`-.__.-'_.-'    _.-'
      `-._    `-.__.-'    _.-'
          `-._        _.-'
              `-.__.-'
```

默认是前端启动

### 配置文件redis.conf

- 配置后台启动

  ```Shell
  daemonize yes
  ```

  默认no改为yes

可以启动了

```shell
./redis-server redis.conf
```

## 2、xcode c++

参考链接：https://www.cnblogs.com/chinxi/p/6184885.html

### 2.1、clone 到本地，编译

Github:https://github.com/redis/hiredis

```shell
git clone git@github.com:redis/hiredis.git
```

编译

```
cd hiredis
make
make install
```

在目录中生成了`libhiredis.dylib`

新建xcode项目

引入动态库`libhiredis.dylib`
头文件搜索路径`/usr/local/install/hiredis`

Demo地址：https://github.com/IcyHeartBX/TestRedisX



# 三、使用

- CRUD

## 1、使用客户端连接

```shell
./redis-cli -h 127.0.0.1 -p 6379
```

或，默认连接

```shell
./redis-cli
```

## 2、redis-cli String操作

![屏幕快照 2018-01-26 下午12.48.29](https://ws3.sinaimg.cn/large/006tKfTcly1fnv9dq4yw5j31800icth4.jpg)

### 2.1、SET增加，修改

`SET key value`

key值存在value则覆盖

范例：

```shell
127.0.0.1:6379> set hello helloworld
OK
127.0.0.1:6379> get hello
"helloworld"
127.0.0.1:6379>
```

### 2.2、GET获取

### 2.3、DEL删除

`del key`删除

```shell
127.0.0.1:6379> del hello
(integer) 1
```

### 2.4、设置有效时间

- 设置

`expire key 时间(按s计算)`

- 取得有效时间

`ttl key`

范例：

```shell
127.0.0.1:6379> expire hello 2000
(integer) 1
127.0.0.1:6379> ttl hello
(integer) 1985
```



注意：redis指令不区分大小写，但处于规范，应该用大写



### 2.5、查看当前所有KEY

```shell
127.0.0.1:6379> KEYS *
1) "HELLO"
2) "hello"
```



## 3、List操作

![屏幕快照 2018-01-26 下午2.26.12](https://ws3.sinaimg.cn/large/006tKfTcly1fnv9drtlh3j31280kwtyz.jpg)

### 3.1、List添加

`LPUSH key value [value ...]`

- key不存在插入一个列表
- key存在，类型不是列表类型返回错误

范例：

```shell
127.0.0.1:6379> LPUSH ticket "xiaoming"
(integer) 1
127.0.0.1:6379> LPUSH ticket "hanmeimei"
(integer) 2
127.0.0.1:6379> LPUSH ticket "lilei"
```

一次性加多个

```
127.0.0.1:6379> RPUSH ticket "zhangsan" "lisi" "wangwu"
(integer) 6
127.0.0.1:6379> LRANGE ticket 0 -1
1) "lilei"
2) "hanmeimei"
3) "xiaoming"
4) "zhangsan"
5) "lisi"
6) "wangwu"
127.0.0.1:6379>
```



### 3.2、显示值LRANGE

`LRANGE key startindex endindex `返回指定区间列表值(0 ~ n)

- key 键
- `startindex` 开始索引
- `endindex`结束索引

范例：

```shell
127.0.0.1:6379> LRANGE ticket 0 2
1) "lilei"
2) "hanmeimei"
3) "xiaoming"
127.0.0.1:6379>
```



### 3.3、取出并移除LPOP RPOP

`LPOP/RPOP key`弹出一个，左弹，右弹

范例：

```shell
127.0.0.1:6379> LRANGE ticket 0 -1
1) "lilei"
2) "hanmeimei"
3) "xiaoming"
4) "zhangsan"
5) "lisi"
6) "wangwu"
127.0.0.1:6379> LPOP ticket
"lilei"
127.0.0.1:6379> RPOP ticket
"wangwu"
127.0.0.1:6379> LRANGE ticket 0 -1
1) "hanmeimei"
2) "xiaoming"
3) "zhangsan"
4) "lisi"
127.0.0.1:6379>
```



### 3.4、 LRAM 左移除

`LRAM key count value`

移除2个从头到尾叫小明的

```shell
127.0.0.1:6379> LRANGE group1 0 -1
1) "xiaoming"
2) "xiaohong"
3) "xiaoming"
4) "xiaohong"
5) "xiaoming"
6) "xiaomhong"
127.0.0.1:6379> LREM group1 2 xiaoming
(integer) 2
127.0.0.1:6379> LRANGE group1 0 -1
1) "xiaohong"
2) "xiaohong"
3) "xiaoming"
4) "xiaomhong"
```

### 3.5、指定返回第几个元素LINDEX

`LINDEX key index`

范例：

```shell
127.0.0.1:6379> LRANGE ticket 0 -1
1) "hanmeimei"
2) "xiaoming"
3) "zhangsan"
4) "lisi"
127.0.0.1:6379> LINDEX ticket 2
"zhangsan"
```



## 4、Set操作

无序，无重复

### 4.1、SADD添加

`SADD key member`

范例：

```shell
127.0.0.1:6379> SADD sgroup "xiaomingya"
(integer) 1
127.0.0.1:6379> SADD sgroup "aboluoya"
(integer) 1
127.0.0.1:6379>
```

### 4.2、SREM移除

`SREM key member`

```shell
127.0.0.1:6379> SREM sgroup "xiaomingya"
(integer) 1
127.0.0.1:6379>
```



### 4.3、列出所有成员SMEMBERS

`smembers key`

```shell
127.0.0.1:6379> SMEMBERS sgroup
1) "aboluoya"
```



### 4.4、元素是否存在SISMEMBER

`SISMEMBER key member`

```shell
127.0.0.1:6379> SMEMBERS sgroup
1) "aboluoya"
127.0.0.1:6379> SISMEMBER sgroup aboluoya
(integer) 1
```

### 4.5、集合移动SMOVE

`SMOVE src dst member`

```Shell
127.0.0.1:6379> SMEMBERS sgroup
1) "xiaozhangya"
2) "xiaomingya"
3) "aboluoya"
4) "xiaohongya"
127.0.0.1:6379> SMEMBERS sgroupa
1) "zhangsanya"
2) "wangwuya"
3) "lisiya"
127.0.0.1:6379> SMOVE sgroupa sgroup zhangsanya
(integer) 1
127.0.0.1:6379> SMEMBERS sgroup
1) "xiaozhangya"
2) "xiaomingya"
3) "aboluoya"
4) "xiaohongya"
5) "zhangsanya"
127.0.0.1:6379> SMEMBERS sgroupa
1) "wangwuya"
2) "lisiya"
127.0.0.1:6379>
```



## 5、SortSet(ZSET)有序集合

### 5.1、添加元素ZADD

`ZADD key 权重 member`

```
27.0.0.1:6379> ZADD zgroup 3 three
(integer) 1
127.0.0.1:6379> ZADD zgroup 2 three
(integer) 0
127.0.0.1:6379> ZADD zgroup 2 three2
(integer) 1
127.0.0.1:6379> ZADD zgroup 9 threx9
(integer) 1
127.0.0.1:6379> ZADD zgroup 9 threx9
(integer) 0
```

### 5.2、取出所有元素ZRANGE

`ZRANGE key startindex endindex [WITHSCORES]`

- WITHSCORES打印权重，可选

范例：

```shell
127.0.0.1:6379> ZRANGE zgroup 0 -1
1) "three"
2) "three2"
3) "threx9"
127.0.0.1:6379> ZRANGE zgroup 0 -1 WITHSCORES
1) "three"
2) "2"
3) "three2"
4) "2"
5) "threx9"
6) "9"
```



### 5.3、移除ZREM

`ZREM key member`

```shell
127.0.0.1:6379> ZREM zgroup three
(integer) 1
```

### 5.4、ZCOUNT 统计多少个

取出score范围元素个数

`ZCOUNT key min max`

```shell
127.0.0.1:6379> ZCOUNT zgroup 0 99
(integer) 2
```



## 6、Hash

### 6.1、HSET添加

`HSET key hkey hvalue`

```SHELL
127.0.0.1:6379> HSET user:100 name xiaozhang
(integer) 1
127.0.0.1:6379> HSET user:100 age 18
(integer) 1
127.0.0.1:6379> HSET user:100 id 100
(integer) 1
```



### 6.2、HGET 取出

`HGET key hkey`

```shell
127.0.0.1:6379> HGET user:100 name
"xiaozhang"
```



### 6.3、HKEYS返回Hash所有的key

`HEKYS key`

```shell
127.0.0.1:6379> HKEYS user:100
1) "name"
2) "age"
3) "id"
```



### 6.4、HVALS返回Hash所有的value

`HVALS key`

```shell
127.0.0.1:6379> HVALS user:100
1) "xiaozhang"
2) "18"
3) "100"
```



### 6.5、HDEL移除

`HDEL key hkey`

```
127.0.0.1:6379> HDEL user:100 name
(integer) 1
```



## 7、事务

### 7.1、MULTI事务开始

### 7.2、事务执行

范例：

```Shell
127.0.0.1:6379> MULTI
OK
127.0.0.1:6379> RPUSH lgroup "abc"
QUEUED
127.0.0.1:6379> RPUSH lgroup "bcd"
QUEUED
127.0.0.1:6379> LRANGE lgroup 0 -1
QUEUED
127.0.0.1:6379> EXEC
1) (integer) 1
2) (integer) 2
3) 1) "abc"
   2) "bcd"
127.0.0.1:6379>
```



## 8、订阅和发布

- 发布:`publish channle1 message`
- 订阅：`subscribe channle1 [channle2]`

订阅

```shell
127.0.0.1:6379> SUBSCRIBE chatroom
Reading messages... (press Ctrl-C to quit)
1) "subscribe"
2) "chatroom"
3) (integer) 1
1) "message"
2) "chatroom"
3) "hello,world"
```

发布

```shell
127.0.0.1:6379> PUBLISH chatroom "hello,world"
(integer) 1
127.0.0.1:6379>
```











# QAQ、

## 1、SET报错

```shell
127.0.0.1:6379> set hello "hellosud"
(error) MISCONF Redis is configured to save RDB snapshots, but it is currently not able to persist on disk. Commands that may modify the data set are disabled, because this instance is configured to report errors during writes if RDB snapshotting fails (stop-writes-on-bgsave-error option). Please check the Redis logs for details about the RDB error.
```

这是由于工作目录没有操作权限所致

```shell
sudo chown tangpengxiang myredis/
```



