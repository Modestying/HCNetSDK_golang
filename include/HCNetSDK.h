#ifndef _HC_NET_SDK_H_
#define _HC_NET_SDK_H_

#ifndef _WINDOWS_
    #if (defined(_WIN32) || defined(_WIN64))
        #include <winsock2.h>
        #include <windows.h>
    #endif
#endif

#ifndef __PLAYRECT_defined
    #define __PLAYRECT_defined
    typedef struct __PLAYRECT
    {
        int x;
        int y;
        int uWidth;
        int uHeight;
    }PLAYRECT;
#endif

#if (defined(_WIN32)) //windows
    typedef  unsigned __int64   UINT64;
    typedef  signed   __int64   INT64;
#elif defined(__linux__) || defined(__APPLE__) //linux
    #define  BOOL  int
      #include <stdint.h>
      typedef uint32_t    DWORD;
      typedef uint16_t    WORD;
      typedef uint16_t    SHORT;
      typedef uint16_t    USHORT;
      typedef int32_t     LONG;
      typedef uint8_t     BYTE;
      typedef uint32_t    UINT;
      typedef void*       LPVOID;
      typedef void*       HANDLE;
      typedef uint32_t *  LPDWORD;
      typedef uint64_t    UINT64;

    #ifndef TRUE
        #define TRUE  1
    #endif
    #ifndef FALSE
        #define FALSE 0
    #endif
    #ifndef NULL
        #define NULL 0
    #endif

    #define __stdcall
    #define CALLBACK

    #define NET_DVR_API extern "C"
    typedef unsigned int   COLORKEY;
    typedef unsigned int   COLORREF;

    #ifndef __HWND_defined
        #define __HWND_defined
        #if defined(__linux__)
            typedef unsigned int HWND;
        #else
            typedef void* HWND;
        #endif
    #endif

    #ifndef __HDC_defined
        #define __HDC_defined
        #if defined(__linux__)
            typedef struct __DC
            {
                void*   surface;        //SDL Surface
                HWND    hWnd;           //HDC window handle
            }DC;
            typedef DC* HDC;
        #else
            typedef void* HDC;
        #endif
    #endif

    typedef struct tagInitInfo
    {
        int uWidth;
        int uHeight;
    }INITINFO;
#endif

#define SERIALNO_LEN            48      //序列号长度
#define NET_DVR_DEV_ADDRESS_MAX_LEN 129
#define NET_DVR_LOGIN_USERNAME_MAX_LEN 64
#define NET_DVR_LOGIN_PASSWD_MAX_LEN 64


#define LIGHT_PWRON        2    /* 接通灯光电源 */
#define WIPER_PWRON        3    /* 接通雨刷开关 */
#define FAN_PWRON        4    /* 接通风扇开关 */
#define HEATER_PWRON    5    /* 接通加热器开关 */
#define AUX_PWRON1        6    /* 接通辅助设备开关 */
#define AUX_PWRON2        7    /* 接通辅助设备开关 */
#define SET_PRESET        8    /* 设置预置点 */
#define CLE_PRESET        9    /* 清除预置点 */

#define ZOOM_IN            11    /* 焦距以速度SS变大(倍率变大) */
#define ZOOM_OUT        12    /* 焦距以速度SS变小(倍率变小) */
#define FOCUS_NEAR      13  /* 焦点以速度SS前调 */
#define FOCUS_FAR       14  /* 焦点以速度SS后调 */
#define IRIS_OPEN       15  /* 光圈以速度SS扩大 */
#define IRIS_CLOSE      16  /* 光圈以速度SS缩小 */

#define TILT_UP            21    /* 云台以SS的速度上仰 */
#define TILT_DOWN        22    /* 云台以SS的速度下俯 */
#define PAN_LEFT        23    /* 云台以SS的速度左转 */
#define PAN_RIGHT        24    /* 云台以SS的速度右转 */
#define UP_LEFT            25    /* 云台以SS的速度上仰和左转 */
#define UP_RIGHT        26    /* 云台以SS的速度上仰和右转 */
#define DOWN_LEFT        27    /* 云台以SS的速度下俯和左转 */
#define DOWN_RIGHT        28    /* 云台以SS的速度下俯和右转 */
#define PAN_AUTO        29    /* 云台以SS的速度左右自动扫描 */

#define FILL_PRE_SEQ    30    /* 将预置点加入巡航序列 */
#define SET_SEQ_DWELL    31    /* 设置巡航点停顿时间 */
#define SET_SEQ_SPEED    32    /* 设置巡航速度 */
#define CLE_PRE_SEQ        33    /* 将预置点从巡航序列中删除 */
#define STA_MEM_CRUISE    34    /* 开始记录轨迹 */
#define STO_MEM_CRUISE    35    /* 停止记录轨迹 */
#define RUN_CRUISE        36    /* 开始轨迹 */
#define RUN_SEQ            37    /* 开始巡航 */
#define STOP_SEQ        38    /* 停止巡航 */
#define GOTO_PRESET        39    /* 快球转到预置点 */

#define DEL_SEQ         43  /* 删除巡航路径 */
#define STOP_CRUISE        44    /* 停止轨迹 */
#define DELETE_CRUISE    45    /* 删除单条轨迹 */
#define DELETE_ALL_CRUISE 46/* 删除所有轨迹 */

#define PAN_CIRCLE      50   /* 云台以SS的速度自动圆周扫描 */
#define DRAG_PTZ        51   /* 拖动PTZ */
#define LINEAR_SCAN     52   /* 区域扫描 */ //2014-03-15
#define CLE_ALL_PRESET  53   /* 预置点全部清除 */
#define CLE_ALL_SEQ     54   /* 巡航全部清除 */
#define CLE_ALL_CRUISE  55   /* 轨迹全部清除 */

#define POPUP_MENU      56   /* 显示操作菜单 */

#define TILT_DOWN_ZOOM_IN    58    /* 云台以SS的速度下俯&&焦距以速度SS变大(倍率变大) */
#define TILT_DOWN_ZOOM_OUT  59  /* 云台以SS的速度下俯&&焦距以速度SS变小(倍率变小) */
#define PAN_LEFT_ZOOM_IN    60  /* 云台以SS的速度左转&&焦距以速度SS变大(倍率变大)*/
#define PAN_LEFT_ZOOM_OUT   61  /* 云台以SS的速度左转&&焦距以速度SS变小(倍率变小)*/
#define PAN_RIGHT_ZOOM_IN    62  /* 云台以SS的速度右转&&焦距以速度SS变大(倍率变大) */
#define PAN_RIGHT_ZOOM_OUT  63  /* 云台以SS的速度右转&&焦距以速度SS变小(倍率变小) */
#define UP_LEFT_ZOOM_IN     64  /* 云台以SS的速度上仰和左转&&焦距以速度SS变大(倍率变大)*/
#define UP_LEFT_ZOOM_OUT    65  /* 云台以SS的速度上仰和左转&&焦距以速度SS变小(倍率变小)*/
#define UP_RIGHT_ZOOM_IN    66  /* 云台以SS的速度上仰和右转&&焦距以速度SS变大(倍率变大)*/
#define UP_RIGHT_ZOOM_OUT   67  /* 云台以SS的速度上仰和右转&&焦距以速度SS变小(倍率变小)*/
#define DOWN_LEFT_ZOOM_IN   68  /* 云台以SS的速度下俯和左转&&焦距以速度SS变大(倍率变大) */
#define DOWN_LEFT_ZOOM_OUT  69  /* 云台以SS的速度下俯和左转&&焦距以速度SS变小(倍率变小) */
#define DOWN_RIGHT_ZOOM_IN    70  /* 云台以SS的速度下俯和右转&&焦距以速度SS变大(倍率变大) */
#define DOWN_RIGHT_ZOOM_OUT    71  /* 云台以SS的速度下俯和右转&&焦距以速度SS变小(倍率变小) */
#define TILT_UP_ZOOM_IN        72    /* 云台以SS的速度上仰&&焦距以速度SS变大(倍率变大) */
#define TILT_UP_ZOOM_OUT    73

//宏定义
#define MAX_NAMELEN                16        //DVR本地登陆名
#define MAX_RIGHT                32        //设备支持的权限（1-12表示本地权限，13-32表示远程权限）
#define NAME_LEN                32      //用户名长度
#define MIN_PASSWD_LEN          8          //最小密码长度
#define PASSWD_LEN                16      //密码长度
#define STREAM_PASSWD_LEN         12      //码流加密密钥最大长度
#define MAX_PASSWD_LEN_EX            64      //密码长度64位
#define GUID_LEN                16      //GUID长度
#define DEV_TYPE_NAME_LEN        24      //设备类型名称长度
#define SERIALNO_LEN            48      //序列号长度
#define MACADDR_LEN                6       //mac地址长度
#define MAC_ADDRESS_NUM         48      //Mac地址长度
#define MAX_INTERVAL_NUM        4    //最大时间间隔个数

// struct

//NET_DVR_Login_V30()参数结构
typedef struct tagNET_DVR_DEVICEINFO_V30
{
    BYTE sSerialNumber[SERIALNO_LEN];  //序列号
    BYTE byAlarmInPortNum;                //报警输入个数
    BYTE byAlarmOutPortNum;                //报警输出个数
    BYTE byDiskNum;                    //硬盘个数
    BYTE byDVRType;                    //设备类型, 1:DVR 2:ATM DVR 3:DVS ......
    BYTE byChanNum;                    //模拟通道个数
    BYTE byStartChan;                    //起始通道号,例如DVS-1,DVR - 1
    BYTE byAudioChanNum;                //语音通道数
    BYTE byIPChanNum;                    //最大数字通道个数，低位
    BYTE byZeroChanNum;            //零通道编码个数 //2010-01-16
    BYTE byMainProto;            //主码流传输协议类型 0-private, 1-rtsp,2-同时支持private和rtsp
    BYTE bySubProto;                //子码流传输协议类型0-private, 1-rtsp,2-同时支持private和rtsp
    BYTE bySupport;
    BYTE bySupport1;
    BYTE bySupport2;
    WORD wDevType;
    BYTE bySupport3;
    BYTE byMultiStreamProto;//是否支持多码流,按位表示,0-不支持,1-支持,bit1-码流3,bit2-码流4,bit7-主码流，bit-8子码流
    BYTE byStartDChan;        //起始数字通道号,0表示无效
    BYTE byStartDTalkChan;    //起始数字对讲通道号，区别于模拟对讲通道号，0表示无效
    BYTE byHighDChanNum;        //数字通道个数，高位
    BYTE bySupport4;
    BYTE byLanguageType;
    BYTE byVoiceInChanNum;   //音频输入通道数
    BYTE byStartVoiceInChanNo; //音频输入起始通道号 0表示无效
    BYTE  bySupport5;
    BYTE  bySupport6;
    BYTE  byMirrorChanNum;    //镜像通道个数，<录播主机中用于表示导播通道>
    WORD wStartMirrorChanNo;  //起始镜像通道号
    BYTE bySupport7;
    BYTE  byRes2;        //保留
}NET_DVR_DEVICEINFO_V30, *LPNET_DVR_DEVICEINFO_V30;

typedef struct tagNET_DVR_DEVICEINFO_V40
{
    NET_DVR_DEVICEINFO_V30 struDeviceV30;
    BYTE  bySupportLock;        //设备支持锁定功能，该字段由SDK根据设备返回值来赋值的。bySupportLock为1时，dwSurplusLockTime和byRetryLoginTime有效
    BYTE  byRetryLoginTime;        //剩余可尝试登陆的次数，用户名，密码错误时，此参数有效
    BYTE  byPasswordLevel;      //admin密码安全等级0-无效，1-默认密码，2-有效密码,3-风险较高的密码。当用户的密码为出厂默认密码（12345）或者风险较高的密码时，上层客户端需要提示用户更改密码。
    BYTE  byProxyType;  //代理类型，0-不使用代理, 1-使用socks5代理, 2-使用EHome代理
    DWORD dwSurplusLockTime;    //剩余时间，单位秒，用户锁定时，此参数有效
    BYTE  byCharEncodeType;     //字符编码类型
    BYTE  bySupportDev5;//支持v50版本的设备参数获取，设备名称和设备类型名称长度扩展为64字节
    BYTE  bySupport;  //能力集扩展，位与结果：0- 不支持，1- 支持
    BYTE  byLoginMode; //登录模式 0-Private登录 1-ISAPI登录
    DWORD dwOEMCode;
    int iResidualValidity;   //该用户密码剩余有效天数，单位：天，返回负值，表示密码已经超期使用，例如“-3表示密码已经超期使用3天”
    BYTE  byResidualValidity; // iResidualValidity字段是否有效，0-无效，1-有效
    BYTE  byRes2[243];
}NET_DVR_DEVICEINFO_V40, *LPNET_DVR_DEVICEINFO_V40;

typedef void (*fLoginResultCallBack) (LONG lUserID, DWORD dwResult, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo , void* pUser);
typedef void (*REALDATACALLBACK) (LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser);

typedef struct tagNET_DVR_USER_LOGIN_INFO
{
    char sDeviceAddress[NET_DVR_DEV_ADDRESS_MAX_LEN];
    BYTE byUseTransport;    //是否启用能力集透传，0--不启用透传，默认，1--启用透传
    WORD wPort;
    char sUserName[NET_DVR_LOGIN_USERNAME_MAX_LEN];
    char sPassword[NET_DVR_LOGIN_PASSWD_MAX_LEN];
    fLoginResultCallBack cbLoginResult;
    void *pUser;
    BOOL bUseAsynLogin;
    BYTE byProxyType; //0:不使用代理，1：使用标准代理，2：使用EHome代理
    BYTE byUseUTCTime;    //0-不进行转换，默认,1-接口上输入输出全部使用UTC时间,SDK完成UTC时间与设备时区的转换,2-接口上输入输出全部使用平台本地时间，SDK完成平台本地时间与设备时区的转换
    BYTE byLoginMode; //0-Private 1-ISAPI 2-自适应
    BYTE byHttps;    //0-不适用tls，1-使用tls 2-自适应
    LONG iProxyID;    //代理服务器序号，添加代理服务器信息时，相对应的服务器数组下表值
    BYTE byVerifyMode;  //认证方式，0-不认证，1-双向认证，2-单向认证；认证仅在使用TLS的时候生效;
    BYTE byRes3[119];
}NET_DVR_USER_LOGIN_INFO,*LPNET_DVR_USER_LOGIN_INFO;

//图片质量
typedef struct tagNET_DVR_JPEGPARA
{
    WORD    wPicSize;
    WORD    wPicQuality;            /* 图片质量系数 0-最好 1-较好 2-一般 */
}NET_DVR_JPEGPARA, *LPNET_DVR_JPEGPARA;

//软解码预览参数
typedef struct tagNET_DVR_CLIENTINFO
{
    LONG lChannel;
    LONG lLinkMode;
    HWND hPlayWnd;
    char* sMultiCastIP;
    BYTE byProtoType;
    BYTE byRes[3];
}NET_DVR_CLIENTINFO, *LPNET_DVR_CLIENTINFO;

#define STREAM_ID_LEN   32

//预览V40接口
typedef struct tagNET_DVR_PREVIEWINFO
{
    LONG lChannel;
    DWORD dwStreamType;
    DWORD dwLinkMode;
    HWND hPlayWnd;
    DWORD bBlocked;
    DWORD bPassbackRecord;
    BYTE byPreviewMode;
    BYTE byStreamID[STREAM_ID_LEN];
    BYTE byProtoType;
    BYTE byRes1;
    BYTE byVideoCodingType;
    DWORD dwDisplayBufNum;
    BYTE byNPQMode;
    BYTE byRes[215];
}NET_DVR_PREVIEWINFO, *LPNET_DVR_PREVIEWINFO;

typedef struct tagNET_DVR_BUF_INFO
{
    void*   pBuf;    //缓冲区指针
    DWORD   nLen;    //缓冲区长度
}NET_DVR_BUF_INFO, *LPNET_DVR_BUF_INFO;

typedef struct tagNET_DVR_IN_PARAM
{
    NET_DVR_BUF_INFO struCondBuf;
    NET_DVR_BUF_INFO struInParamBuf;
    DWORD  dwRecvTimeout;
    BYTE   byRes[32];
}NET_DVR_IN_PARAM,LPNET_DVR_IN_PARAM;

typedef struct tagNET_DVR_OUT_PARAM
{
    NET_DVR_BUF_INFO struOutBuf;
    void*  lpStatusList;
    BYTE   byRes[32];
}NET_DVR_OUT_PARAM,LPNET_DVR_OUT_PARAM;


typedef struct tagNET_DVR_SETUPALARM_PARAM
{
    DWORD dwSize;
    BYTE  byLevel; //布防优先级，0-一等级（高），1-二等级（中），2-三等级（低）
    BYTE  byAlarmInfoType; //上传报警信息类型（抓拍机支持），0-老报警信息（NET_DVR_PLATE_RESULT），1-新报警信息(NET_ITS_PLATE_RESULT)2012-9-28
    BYTE  byRetAlarmTypeV40; //0--返回NET_DVR_ALARMINFO_V30或NET_DVR_ALARMINFO, 1--设备支持NET_DVR_ALARMINFO_V40则返回NET_DVR_ALARMINFO_V40，不支持则返回NET_DVR_ALARMINFO_V30或NET_DVR_ALARMINFO
    BYTE  byRetDevInfoVersion; //CVR上传报警信息回调结构体版本号 0-COMM_ALARM_DEVICE， 1-COMM_ALARM_DEVICE_V40
    BYTE  byRetVQDAlarmType; //VQD报警上传类型，0-上传报报警NET_DVR_VQD_DIAGNOSE_INFO，1-上传报警NET_DVR_VQD_ALARM
    //1-表示人脸侦测报警扩展(INTER_FACE_DETECTION),0-表示原先支持结构(INTER_FACESNAP_RESULT)
    BYTE  byFaceAlarmDetection;
    //Bit0- 表示二级布防是否上传图片: 0-上传，1-不上传
    //Bit1- 表示开启数据上传确认机制；0-不开启，1-开启
    //Bit6- 表示雷达检测报警(eventType:radarDetection)是否开启实时上传；0-不开启，1-开启（用于web插件实时显示雷达目标轨迹）
    BYTE  bySupport;
    //断网续传类型
    //bit0-车牌检测（IPC） （0-不续传，1-续传）
    //bit1-客流统计（IPC）  （0-不续传，1-续传）
    //bit2-热度图统计（IPC） （0-不续传，1-续传）
    //bit3-人脸抓拍（IPC） （0-不续传，1-续传）
    //bit4-人脸对比（IPC） （0-不续传，1-续传）
    BYTE  byBrokenNetHttp;
    WORD  wTaskNo;    //任务处理号 和 (上传数据NET_DVR_VEHICLE_RECOG_RESULT中的字段dwTaskNo对应 同时 下发任务结构 NET_DVR_VEHICLE_RECOG_COND中的字段dwTaskNo对应)
    BYTE  byDeployType;    //布防类型：0-客户端布防，1-实时布防
    BYTE  bySubScription;	//订阅，按位表示，未开启订阅不上报  //占位
    //Bit7-移动侦测人车分类是否传图；0-不传图(V30上报)，1-传图(V40上报)
    BYTE  byRes1[2];
    BYTE  byAlarmTypeURL;//bit0-表示人脸抓拍报警上传（INTER_FACESNAP_RESULT）；0-表示二进制传输，1-表示URL传输（设备支持的情况下，设备支持能力根据具体报警能力集判断,同时设备需要支持URL的相关服务，当前是”云存储“）
    //bit1-表示EVENT_JSON中图片数据长传类型；0-表示二进制传输，1-表示URL传输（设备支持的情况下，设备支持能力根据具体报警能力集判断）
    //bit2 - 人脸比对(报警类型为COMM_SNAP_MATCH_ALARM)中图片数据上传类型：0 - 二进制传输，1 - URL传输
    //bit3 - 行为分析(报警类型为COMM_ALARM_RULE)中图片数据上传类型：0 - 二进制传输，1 - URL传输，本字段设备是否支持，对应软硬件能力集中<isSupportBehaviorUploadByCloudStorageURL>节点是否返回且为true
    BYTE  byCustomCtrl;//Bit0- 表示支持副驾驶人脸子图上传: 0-不上传,1-上传
}NET_DVR_SETUPALARM_PARAM, *LPNET_DVR_SETUPALARM_PARAM;


//单IO触发抓拍功能配置
typedef struct tagNET_DVR_SNAPCFG
{
    DWORD   dwSize;
    BYTE    byRelatedDriveWay;//触发IO关联的车道号
    BYTE     bySnapTimes; //线圈抓拍次数，0-不抓拍，非0-连拍次数，目前最大5次
    WORD    wSnapWaitTime;  //抓拍等待时间，单位ms，取值范围[0,60000]
    WORD    wIntervalTime[MAX_INTERVAL_NUM];//连拍间隔时间，ms
    DWORD   dwSnapVehicleNum; //抓拍车辆序号。
    NET_DVR_JPEGPARA  struJpegPara;//抓拍图片参数
    BYTE    byRes2[16];//保留字节
}NET_DVR_SNAPCFG, *LPNET_DVR_SNAPCFG;


//报警设备信息
typedef struct
{
    BYTE byUserIDValid;                 /* userid是否有效 0-无效，1-有效 */
    BYTE bySerialValid;                 /* 序列号是否有效 0-无效，1-有效 */
    BYTE byVersionValid;                /* 版本号是否有效 0-无效，1-有效 */
    BYTE byDeviceNameValid;             /* 设备名字是否有效 0-无效，1-有效 */
    BYTE byMacAddrValid;                /* MAC地址是否有效 0-无效，1-有效 */
    BYTE byLinkPortValid;               /* login端口是否有效 0-无效，1-有效 */
    BYTE byDeviceIPValid;               /* 设备IP是否有效 0-无效，1-有效 */
    BYTE bySocketIPValid;               /* socket ip是否有效 0-无效，1-有效 */
    LONG lUserID;                       /* NET_DVR_Login()返回值, 布防时有效 */
    BYTE sSerialNumber[SERIALNO_LEN];    /* 序列号 */
    DWORD dwDeviceVersion;                /* 版本信息 高16位表示主版本，低16位表示次版本*/
    char sDeviceName[NAME_LEN];            /* 设备名字 */
    BYTE byMacAddr[MACADDR_LEN];        /* MAC地址 */
    WORD wLinkPort;                     /* link port */
    char sDeviceIP[128];                /* IP地址 */
    char sSocketIP[128];                /* 报警主动上传时的socket IP地址 */
    BYTE byIpProtocol;                  /* Ip协议 0-IPV4, 1-IPV6 */
    BYTE byRes1[2];
    BYTE bJSONBroken;                   //JSON断网续传标志。0：不续传；1：续传
    WORD wSocketPort;
    BYTE byRes2[6];
}NET_DVR_ALARMER, *LPNET_DVR_ALARMER;

//sdk function
DWORD NET_DVR_GetSDKVersion();
DWORD NET_DVR_GetSDKBuildVersion();
int NET_DVR_IsSupport();

// sdk init
BOOL NET_DVR_Init();
BOOL NET_DVR_Cleanup();

//  login device
LONG NET_DVR_Login_V30(char *sDVRIP, WORD wDVRPort, char *sUserName, char *sPassword, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo);
LONG NET_DVR_Login_V40(LPNET_DVR_USER_LOGIN_INFO pLoginInfo,LPNET_DVR_DEVICEINFO_V40 lpDeviceInfo);
BOOL NET_DVR_Logout(LONG lUserID);
BOOL NET_DVR_Logout_V30(LONG lUserID);

// connect device
BOOL NET_DVR_SetConnectTime(DWORD dwWaitTime, DWORD dwTryTimes);
BOOL NET_DVR_SetReconnect(DWORD dwInterval, BOOL bEnableRecon);

// sdk capture
BOOL NET_DVR_CaptureJPEGPicture(LONG lUserID, LONG lChannel, LPNET_DVR_JPEGPARA lpJpegPara, char *sPicFileName);
BOOL NET_DVR_CaptureJPEGPicture(LONG lUserID, LONG lChannel, LPNET_DVR_JPEGPARA lpJpegPara, char *sPicFileName);

// stream play control
LONG NET_DVR_RealPlay_V30(LONG lUserID, LPNET_DVR_CLIENTINFO lpClientInfo, void(*fRealDataCallBack_V30) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser), void* pUser, BOOL bBlocked);
BOOL NET_DVR_ClosePreview(LONG lUserID, DWORD nSessionID);
BOOL NET_DVR_ClosePlayBack(LONG lUserID, DWORD nSessionID);
LONG NET_DVR_RealPlay_V40(LONG lUserID, LPNET_DVR_PREVIEWINFO lpPreviewInfo, REALDATACALLBACK fRealDataCallBack_V30, void* pUser);
BOOL NET_DVR_StopRealPlay(LONG lRealHandle);

BOOL NET_DVR_SaveRealData(LONG lRealHandle,char *sFileName);
BOOL NET_DVR_StopSaveRealData(LONG lRealHandle);

// device ptz control
BOOL NET_DVR_PTZControlWithSpeed(LONG lRealHandle, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);

DWORD NET_DVR_GetLastError();

// alarm
BOOL NET_DVR_GetDeviceAbility(LONG lUserID, DWORD dwAbilityType, char* pInBuf, DWORD dwInLength, char* pOutBuf, DWORD dwOutLength);

BOOL NET_DVR_GetDVRConfig(LONG lUserID, DWORD dwCommand,LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
BOOL NET_DVR_SetDVRConfig(LONG lUserID, DWORD dwCommand,LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize);

BOOL NET_DVR_GetDeviceConfig(LONG lUserID, DWORD dwCommand, DWORD dwCount, LPVOID lpInBuffer, DWORD dwInBufferSize, LPVOID lpStatusList, LPVOID lpOutBuffer, DWORD dwOutBufferSize);
BOOL NET_DVR_SetDeviceConfigEx(LONG lUserID, DWORD dwCommand, DWORD dwCount, NET_DVR_IN_PARAM *lpInParam, NET_DVR_OUT_PARAM *lpOutParam);

// 报警消息回调
typedef void (CALLBACK *MSGCallBack)(LONG lCommand, NET_DVR_ALARMER *pAlarmer, char *pAlarmInfo, DWORD dwBufLen, void* pUser);
BOOL NET_DVR_SetDVRMessageCallBack_V30(MSGCallBack fMessageCallBack, void* pUser);
typedef BOOL (CALLBACK *MSGCallBack_V31)(LONG lCommand, NET_DVR_ALARMER *pAlarmer, char *pAlarmInfo, DWORD dwBufLen, void* pUser);
BOOL NET_DVR_SetDVRMessageCallBack_V31(MSGCallBack_V31 fMessageCallBack, void* pUser);
BOOL NET_DVR_SetDVRMessageCallBack_V50(int iIndex, MSGCallBack fMessageCallBack, void* pUser);
BOOL NET_DVR_SetDVRMessageCallBack_V51(int iIndex, MSGCallBack fMsgCallBack, void* pUser);


// 报警消息监听
BOOL NET_DVR_StartListen(char *sLocalIP,WORD wLocalPort);
BOOL NET_DVR_StopListen();

LONG NET_DVR_StartListen_V30(char *sLocalIP, WORD wLocalPort, MSGCallBack DataCallback, void* pUserData);
BOOL NET_DVR_StopListen_V30(LONG lListenHandle);
BOOL NET_DVR_ContinuousShoot(LONG lUserID, LPNET_DVR_SNAPCFG lpInter);

//报警
LONG NET_DVR_SetupAlarmChan(LONG lUserID);
BOOL NET_DVR_CloseAlarmChan(LONG lAlarmHandle);
LONG NET_DVR_SetupAlarmChan_V30(LONG lUserID);
BOOL NET_DVR_CloseAlarmChan_V30(LONG lAlarmHandle);
LONG NET_DVR_SetupAlarmChan_V41(LONG lUserID, LPNET_DVR_SETUPALARM_PARAM lpSetupParam);


// car capture

//BOOL NET_DVR_ManualSnap(LONG lUserID, NET_DVR_MANUALSNAP const* lpInter, LPNET_DVR_PLATE_RESULT lpOuter);
BOOL NET_DVR_ContinuousShoot(LONG lUserID, LPNET_DVR_SNAPCFG lpInter);

#endif