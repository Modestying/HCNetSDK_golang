# 海康HCNetSDK-GO版本

>参考连接
><https://www.cnblogs.com/dust90/p/11447622.htm>
>

## 免责说明
 仓库文件示例仅供大家学习参考，工作使用请阅读`项目说明`第二条
 
## 项目说明
 
* 海康SDK实现Golang调用，实现基础的常用功能
* 实际开发场景可能会大量使用`unsafe.Pointer`，有**一定的风险**，如果确定使用，建议由经验丰富的开发人员进行`Code Review`工作
* 可以根据自己需求修改`include`下`HCNetSDK.h`
* 遇到问题/有需求请提交 Issues，一起讨论
* demo.go为参考链接示例，不包含报警功能
* 默认为linux平台开发，再Windows平台请根据提示修改`HKDevice.go`中对应的变量类型

## 实现功能

1. 报警功能，只有布防方式可用，监听方式无法收到报警消息
2. 云台控制，个人测试正常
3. 视频预览，目前只是正常调用sdk，未进行界面视频预览

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
## 联系方式

* https://www.cnblogs.com/erfeng/