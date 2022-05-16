package Device

type Device interface {
	Login() (int, error)
	Logout() error
	SetAlarmCallBack() error
	StartListenAlarmMsg() error
	StopListenAlarmMsg() error
}
type DeviceInfo struct {
	IP       string
	Port     int
	UserName string
	Password string
}
