package main

import (
	"alarm/internal/Device"
	"fmt"
	"runtime"
)

func init() {
	Device.InitHikSDK()
}

func main() {
	fmt.Println(runtime.GOOS)
	info := Device.DeviceInfo{
		IP:       "192.168.0.66",
		UserName: "admin",
		Password: "admin508",
		Port:     8000,
	}
	device := Device.NewHKDevice(info)
	if _, err := device.Login(); err != nil {
		fmt.Println(err.Error())
	} else {
		fmt.Println("success login")
	}
	defer func() {
		device.Logout()
		Device.HKExit()
	}()

	// device.SetAlarmCallBack()
	// device.StartListenAlarmMsg()
	// time.Sleep(time.Second * 100)
	// device.StopListenAlarmMsg()
}
