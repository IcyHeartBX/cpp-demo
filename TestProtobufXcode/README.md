> mac protobuf c++

要在mac上使用protobuf,并用在xcode中
需要做如下操作

# 安装
- clone 代码

github地址：https://github.com/google/protobuf

`git clone git@github.com:google/protobuf.git`

- 编译&安装

cd protobuf根目录

./autogen.sh是获取GoogleMock，并生成对应的configure脚本

`./autogen.sh`

`./configure --prefix=/usr/local/install/protobuf`

`make`

`make install`

- 配置环境变量

`vi ~/.bash_profile`

```
 #protobuf protoc evn
 PROTOBUF_HOME=/usr/local/install/protobuf
 export PATH=$PATH:$PROTOBUF_HOME/bin
```

protoc --version

# xcode中使用

创建c++项目

General --> Linked Frameworks and Libraries-->+-->Add Other

/usr/local/install/protobuf/lib/libprotoc.15.dylib 导入

Build Setting-->Search Paths-->Header Search Path-->/usr/local/install/protobuf/include加入

配置完成

环境搭建完毕

代码参考
https://www.cnblogs.com/zhouyang209117/p/7218719.html

https://www.cnblogs.com/stephen-liu74/archive/2013/01/04/2842533.html
