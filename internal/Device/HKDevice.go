package Device

/*
#cgo CFLAGS:  -I../../include
#cgo LDFLAGS: -L$../../build  -lHCCore -lHCNETSDK -lhpr
#include <stdio.h>
#include <stdlib.h>
#include "HCNetSDK.h"
extern void AlarmCallBack(LONG lCommand, NET_DVR_ALARMER *pAlarmer, char *pAlarmInfo, DWORD dwBufLen, void* pUser);
*/
import "C"
import (
	"errors"
	"fmt"
	"log"
	"unsafe"
)

//export AlarmCallBack
func AlarmCallBack(command C.LONG, alarm *C.NET_DVR_ALARMER, info *C.char, len C.DWORD, user unsafe.Pointer) {
	fmt.Println("receive alarm")
}

type HKDevice struct {
	ip          string
	port        int
	username    string
	password    string
	loginId     int
	alarmHandle int
}

//InitHikSDK hk sdk init
func InitHikSDK() {
	C.NET_DVR_Init()
	C.NET_DVR_SetConnectTime(2000, 5)
	C.NET_DVR_SetReconnect(10000, 1)
}

//HKExit hk sdk clean
func HKExit() {
	C.NET_DVR_Cleanup()
}

//NewHKDevice new hk-device instance
func NewHKDevice(info DeviceInfo) Device {
	return &HKDevice{
		ip:       info.IP,
		port:     info.Port,
		username: info.UserName,
		password: info.Password}
}

//Login hk device loin
func (device *HKDevice) Login() (int, error) {
	// init data
	var deviceInfoV30 C.NET_DVR_DEVICEINFO_V30
	ip := C.CString(device.ip)
	usr := C.CString(device.username)
	passwd := C.CString(device.password)
	defer func() {
		C.free(unsafe.Pointer(ip))
		C.free(unsafe.Pointer(usr))
		C.free(unsafe.Pointer(passwd))
	}()

	device.loginId = int(C.NET_DVR_Login_V30(ip, C.WORD(device.port), usr, passwd,
		(*C.NET_DVR_DEVICEINFO_V30)(unsafe.Pointer(&deviceInfoV30)),
	))
	if device.loginId < 0 {
		return -1, device.HKErr("login ")
	}
	log.Println("login success")
	return device.loginId, nil
}

//Logout hk device logout
func (device *HKDevice) Logout() error {
	C.NET_DVR_Logout_V30(C.LONG(device.loginId))
	if err := device.HKErr("NVRLogout"); err != nil {
		return err
	}
	return nil
}

func (device *HKDevice) SetAlarmCallBack() error {
	if C.NET_DVR_SetDVRMessageCallBack_V30(C.MSGCallBack(C.AlarmCallBack), C.NULL) != C.TRUE {
		return device.HKErr(device.ip + ":set alarm callback")
	}
	return nil
}
func (device *HKDevice) StartListenAlarmMsg() error {
	var struAlarmParam C.NET_DVR_SETUPALARM_PARAM
	struAlarmParam.dwSize = C.uint(unsafe.Sizeof(struAlarmParam)) //Windows -> C.ulong
	struAlarmParam.byAlarmInfoType = 0

	device.alarmHandle = int(C.NET_DVR_SetupAlarmChan_V41(C.int(device.loginId), &struAlarmParam)) // Windows -> C.long
	if device.alarmHandle < 0 {
		return device.HKErr("setup alarm chan")
	}
	return nil
}

func (device *HKDevice) StopListenAlarmMsg() error {
	if C.NET_DVR_CloseAlarmChan_V30(C.int(device.alarmHandle)) != C.TRUE { //Windows  C.long
		return device.HKErr("stoop alarm chan")
	}
	return nil
}

//HKErr Detect success of operation
func (device *HKDevice) HKErr(operation string) error {
	errno := int64(C.NET_DVR_GetLastError())
	if errno > 0 {
		reMsg := fmt.Sprintf("%s:%s摄像头失败,失败代码号：%d", device.ip, operation, errno)
		return errors.New(reMsg)
	}
	return nil
}
