#pragma once
#include <QObject>
#include "data.h"

class DataPacket : public QObject {
	Q_OBJECT

public:
	DataPacket(QObject * parent = 0);
	~DataPacket();

	void setPacket(Data &metaData, TrainCmd trainCmd);
	QByteArray getPcaket();
private:
	Data metaData;
	TrainCmd m_trainCmd;
	QByteArray m_packetData;
};
