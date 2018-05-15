#include "data.h"
#include <iostream>
#include <math.h>

using namespace std;

Data::Data(QObject * parent) 
	: QObject(parent) 
	,m_timerId(0)
	,m_steps(0)
	,m_realTime(0.0)
{
	m_timerId = startTimer(0);
	m_time.start();
}

Data::~Data() 
{

}

void Data::timerEvent(QTimerEvent * event)
{
	/////////////////////////////////
	QObject::timerEvent(event);
	/////////////////////////////////

	float timeStep = m_time.restart();

	m_realTime = m_realTime + timeStep / 1000.0f;

	DatastateAck.speed		= 50.0f * sin(m_realTime / 10.0f) + 50.0f; //速度
	DatastateAck.Direction	= 100.0f * sin(m_realTime / 10.0f);     // 方向
	DatastateAck.Power      = 5.0f * sin(m_realTime / 10.0f)+ 5.0f;     //电量，0-5 
	DatastateAck.Temp       = 128.0f * sin(m_realTime / 20.0f);      //温度 +-128 
	DatastateAck.Hum		= 50.0f  * sin(m_realTime / 20.0f)+50.0f;		 //湿度 百分之 0-100 
	DatastateAck.Roll		= 180.0f * sin(m_realTime / 10.0f);    	 //侧倾角 
	DatastateAck.pitch		= 90.0f * sin(m_realTime / 20.0f);	 //俯仰角 
	DatastateAck.Yaw		= 360.0f * sin(m_realTime / 10.0f);       //航向角 0-360
	DatastateAck.pointID	= 0.0f	;	 //编队ID
	DatastateAck.v			= 125.0f * sin(m_realTime / 10.0f) + 125.0f;	 //航速
	DatastateAck.NowDeepth	= 50 * sin(m_realTime / 10.0f) + 50.0f	; //当前深度 单位米 
	DatastateAck.point.x	= 50 * sin(m_realTime / 10.0f) + 50.0f	;//设备坐标 无效坐标 (0,0)
	DatastateAck.point.y    = 50 * sin(m_realTime / 10.0f) + 50.0f;//设备坐标 无效坐标 (0,0)

	m_Code = QByteArray::fromRawData((char*)&DatastateAck, sizeof(DatastateAck));
	emit valueChanged();
}
