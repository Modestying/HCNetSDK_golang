# 海康HCNetSDK-GO版本

>参考连接
><https://www.cnblogs.com/dust90/p/11447622.htm>
>
## 项目说明

* 海康SDK实现Golang调用
* 根据自己需求修改`include`下`HCNetSDK.h`
* 遇到问题/有需求请提交 Issues，一起讨论

## 实现功能

1. 报警功能  
2. 云台控制  
3. 视频预览

## 使用说明

1. goland 编译器即可运行

2. makefile编译

    ```shell
    Windows:
    mingw32-make.exe windows
    Linux:
    make linux
    ```

    清除

    ```shell
    Windows:
    mingw32-make.exe clean
    Linux:
    make clean
    ```

## 问题记录

1. Linux遇到错误29  
`Ans`: 环境没配好，把`lib/linux`下的文件扔到`/usr/lib/`下面就好了
