package main

/*
#cgo CFLAGS:  -I./include
#cgo LDFLAGS: -L./lib/Linux -lhcnetsdk
#cgo LDFLAGS:-Wl,-rpath,./lib/Linux
*/
import "C"

import (
	"alarm/internal/Device"
	"log"
	"time"
)

func init() {
	Device.InitHikSDK()
}

func main() {
	info := Device.DeviceInfo{
		IP:       "192.168.0.66",
		UserName: "admin",
		Password: "admin508",
		Port:     8000,
	}
	device := Device.NewHKDevice(info)
	if _, err := device.Login(); err != nil {
		log.Println(err.Error())
	} else {
		log.Println("success login")
	}
	defer func() {
		device.Logout()
		Device.HKExit()
	}()

	device.SetAlarmCallBack()
	device.StartListenAlarmMsg()
	time.Sleep(time.Second * 100)
	device.StopListenAlarmMsg()
}
