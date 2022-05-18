package main

/*
#cgo CFLAGS:  -I./include
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "HCNetSDK.h"
*/
import "C"
import (
	"fmt"
	"log"
	"time"
	"unsafe"

	"github.com/pkg/errors"
)
# 参考链接示例，比较粗糙，没有仔细修改，仅供大家参考
# 1.云台控制
# 2.抓图
# 3.视频播放

// 是否有错误
func isErr(oper string) error {
	errno := int64(C.NET_DVR_GetLastError())
	if errno > 0 {
		reMsg := fmt.Sprintf("%s摄像头失败,失败代码号：%d", oper, errno)
		return errors.New(reMsg)
	}
	return nil
}

// Init 初始化海康摄像头
func Init() (err error) {
	C.NET_DVR_Init()
	if err = isErr("Init"); err != nil {
		return
	}
	// 设置连接时间
	C.NET_DVR_SetConnectTime(C.DWORD(2000), C.DWORD(1))
	if err = isErr("SetConnectTime"); err != nil {
		return
	}
	log.Println("Success Init ")
	return nil
}

// Login 登录摄像头
func Login() (int64, error) {
	var deviceinfoV30 C.NET_DVR_DEVICEINFO_V30
	c_ip := C.CString("192.168.10.240")
	defer C.free(unsafe.Pointer(c_ip))

	c_login := C.CString("admin")
	defer C.free(unsafe.Pointer(c_login))

	c_password := C.CString("admin508")
	defer C.free(unsafe.Pointer(c_password))

	msgId := C.NET_DVR_Login_V30(c_ip, C.WORD(8000), c_login, c_password,
		(*C.NET_DVR_DEVICEINFO_V30)(unsafe.Pointer(&deviceinfoV30)),
	)

	if int64(msgId) < 0 {
		if err := isErr("Login"); err != nil {
			return -1, err
		}
		return -1, errors.New("登录摄像头失败")
	}
	log.Println("Success login ,user id  ", msgId)
	return int64(msgId), nil
}

// Logout 退出摄像头登录
// uid:摄像头登录成功的id
func Logout(uid int64) error {
	C.NET_DVR_Logout_V30(C.LONG(uid))
	if err := isErr("Logout"); err != nil {
		return err
	}
	return nil
}

// Play 播放视频
// uid:摄像头登录成功的id
// 返回播放视频标识 pid
func Play(uid int64) (int64, error) {
	var pDetectInfo C.NET_DVR_CLIENTINFO
	pDetectInfo.lChannel = C.LONG(1)
	pid := C.NET_DVR_RealPlay_V30(C.LONG(uid), (*C.NET_DVR_CLIENTINFO)(unsafe.Pointer(&pDetectInfo)), nil, nil, C.BOOL(1))
	if int64(pid) < 0 {
		if err := isErr("Play"); err != nil {
			return -1, err
		}
		return -1, errors.New("播放失败")
	}

	return int64(pid), nil
}

// Capture 抓拍
func Capture(uid int64) (string, error) {
	picPath := time.Now().Format("20060102150405") + ".jpeg"

	var jpegpara C.NET_DVR_JPEGPARA
	var lChannel uint32 = 1
	c_path := C.CString(picPath)
	defer C.free(unsafe.Pointer(c_path))
	msgId := C.NET_DVR_CaptureJPEGPicture(C.LONG(uid), C.LONG(lChannel),
		(*C.NET_DVR_JPEGPARA)(unsafe.Pointer(&jpegpara)),
		c_path,
	)

	if int64(msgId) < 0 {
		if err := isErr("Capture"); err != nil {
			return "", err
		}
		return "", errors.New("抓拍失败")
	}
	return picPath, nil
}

// PtzStop 停止相机
// pid 播放标识符
func PtzStop(pid int64) error {
	msgId := C.NET_DVR_StopRealPlay(C.LONG(pid))
	if int64(msgId) < 0 {
		if err := isErr("PtzStop"); err != nil {
			return err
		}
		return errors.New("停止相机失败")
	}
	return nil
}

// PtzControlStart 云台控制 向左
func PtzControlStart(pid int64) error {
	res := C.NET_DVR_PTZControlWithSpeed(C.LONG(pid), C.DWORD(23), C.DWORD(0), C.DWORD(5))
	log.Println(res)
	if res == 0 {
		log.Println("fail control")
		if err := isErr("NET_DVR_PTZControlWithSpeed Start"); err != nil {
			return err
		}
	}
	return nil
}

// PtzControlStop 停止
func PtzControlStop(pid int64) error {
	res := C.NET_DVR_PTZControlWithSpeed(C.LONG(pid), C.DWORD(23), C.DWORD(1), C.DWORD(2))
	log.Println(res)
	if res == 0 {
		log.Println("fail control")
		if err := isErr("NET_DVR_PTZControlWithSpeed stop"); err != nil {
			return err
		}
	}
	return nil
}

// Close 释放SDK资源，在程序结束之前调用。
func Close() {
	C.NET_DVR_Cleanup()
}

func main() {
	var err error
	err = Init()
	defer Close()
	if err != nil {
		log.Fatal(err.Error())
	}

	var uid int64
	if uid, err = Login(); err != nil {
		log.Fatal(err.Error())
	}

	res, _ := Play(uid)
	log.Println("Play:", res)

	log.Println(res)
	var picPath string
	if picPath, err = Capture(uid); err != nil {
		log.Fatal(err.Error())
	}
	log.Println("图片路径:", picPath)

	var pid int64
	if pid, err = Play(uid); err != nil {
		log.Fatal(err.Error())
	}

	if err = PtzControlStart(pid); err != nil {
		log.Fatal(err.Error())
	}
	time.Sleep(5 * time.Second)
	if err = PtzControlStop(pid); err != nil {
		log.Fatal(err.Error())
	}

	if err = PtzStop(pid); err != nil {
		log.Fatal(err.Error())
	}

	if err = Logout(uid); err != nil {
		log.Fatal(err.Error())
	}
}
