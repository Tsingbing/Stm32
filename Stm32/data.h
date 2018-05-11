#pragma once
#include <QObject>
#include <QTime>

#define PackageMaxLength 256
#define PackageMinLength 7
#define PackageHead 0xAA
#define PackageTail 0xBB
#define MasterID 0xFE //上帝ID 
#define PublicID 0xFF//透传ID
/***设置自身ID***/
#define MyID 0x01 //自身ID  


typedef struct
{
	float x, y, z;    //设备三维坐标 
}Point3f_TypeDef;
typedef struct
{
	float x, y;    //设备二维坐标 
}Point2f_TypeDef;

typedef struct
{
	int x, y, z;    //设备三维坐标 
}Point3d_TypeDef;
typedef struct
{
	int x, y;    //设备二维坐标 
}Point2d_TypeDef;
/*************************/
#pragma pack(4)
typedef struct
{
	char	Head;
	char  PackageLength;//整包长 
	char	SendID;
	char	ReceivedID;
	char	Cmd;
	char	*Code;
	char	Tail;
}DataPackage_TypeDef;
#pragma pack()

typedef enum
{
	CMD_MOVE = 0,//设备运动控制  no feedback 
	CMD_STATE,//设备状态信息 
	CMD_FORMATE,//队形		
	CMD_LASERCONTROL,//激光透传 
	CMD_PICTUREINF,//目标图片信息 
	CMD_GPSCOORD,//GPS坐标  二维 
	CMD_SOUNDCONTROL,//水听器采集数据控制 
	CMD_DOWNLOADCONTROL//程序加载控制 
}TrainCmd;

#pragma pack(4)
typedef struct
{ /******方向或角度控制左负右正*****/
	char  Speed;	//正负100 //油门百分比 负数代表反向 
	char  Direction;//正负100 //油门 
	char   lightpower;//设备灯控 0-100 亮度 
	char  Deepset;	//-100 ~ +100
	char  Roll;    //定侧倾角  默认 0度 
	char  Yaw;     //定向  ENABLE:开始锁定	DISABLE 
}Data_MOVE_TypeDef;
#pragma pack()

typedef struct
{
	unsigned char Get;	//ENABLE	DISABLE
}Data_CMDGet_TypeDef;

#pragma pack(4)
typedef struct
{
	char  speed, Direction;//速度 方向
	char  Power;     //电量，0-5 
	char  Temp;      //温度 +-128 
	char  Hum;		 //湿度 百分之 0-100 
	char  Roll;    	 //侧倾角 
	char  pitch;	 //俯仰角 
	quint8	pointID;	 //编队ID
	short Yaw;       //航向角 0-360
	float v;	 //航速
	float NowDeepth; //当前深度 单位米 
	Point2f_TypeDef point;//设备坐标 无效坐标 (0,0)
}Data_STATEACK_TypeDef;
#pragma pack()


typedef struct
{
	Point3f_TypeDef pt;
	//float x,y,z;    //设备三维坐标 
}Data_COORD_TypeDef;


typedef struct
{
	Point2f_TypeDef pt;
	//float longitude,latitude;     //设备GPS坐标 
}Data_GPSCOORD_TypeDef;


typedef enum
{
	Formate_Line = 0,//线型队形 
	Formate_Auto //自动相对间隔 
}Formate_3;

typedef struct
{
	unsigned char EnOrDisEN;	//ENABLE	DISABLE 
	unsigned char formates;     //队形
	unsigned char PointID;		//决定Leader （ID=0） 其余顺延 
	float Interval;     		//间距(米)
	unsigned char Angle;     			//角度 左负右正line： 0~180
}Data_FORMATE_TypeDef;

typedef struct
{
	unsigned char EnOrDisEN;	//ENABLE	DISABLE设备激光透传 开启，自动启动
}Data_LASERRet_TypeDef;
typedef struct
{
	unsigned char EnOrDisEN;	//ENABLE	DISABLE设备激光透传 开使 ：发透传包 计数  结束 +计数 
}Data_LASERAck_TypeDef;

typedef struct
{//左负右正
	int    directx;	//偏离方向
	int    directy;	//偏离方向
	float  length; 	//距离 
}Data_PICTUREINF_TypeDef;

typedef struct
{
	quint8 RorWCro; 				//开始读所有数据，并清空缓存R:0  W:1  clear：2 NO:0XFF
	quint8 GetFS;	 				//水听器频谱数据控制  开启或结束获取，开启。触发一次并返回频谱 
}Data_SOUNDCONTROL_TypeDef;

typedef struct
{
	unsigned char FScode[250];//512点fft 
}Data_SOUNDFSACK_TypeDef;

typedef struct
{
	unsigned char EnOrDisEN;	//ENABLE	DISABLE
	long long	cnt;//包长度 计数 
}Data_SOUNDAck_TypeDef;

typedef enum
{
	Boot_Reset = 0,
	Boot_JumpToAPP
}BootloaderCmd;
typedef struct
{
	quint8 Cmd;     //设备程序加载控制  
	quint8 Ask;     //对应命令回复 
}Data_DOWNLOADCONTROL_TypeDef;


class Data : public QObject {
	Q_OBJECT

public:
	Data(QObject * parent = 0);
	~Data();
	Data_STATEACK_TypeDef DatastateAck;
	
	QByteArray m_Code;
signals:
	void valueChanged();

protected:
	void timerEvent(QTimerEvent *event);

private:
	int m_timerId;
	int m_steps;
	float m_realTime;
	QTime m_time;
};



