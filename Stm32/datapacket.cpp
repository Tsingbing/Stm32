#include "datapacket.h"

DataPacket::DataPacket(QObject * parent) : QObject(parent) {
	
}

DataPacket::~DataPacket() {
	
}

void DataPacket::setPacket(Data &metaData , TrainCmd m_trainCmd)
{
	QByteArray Code;  //
	m_packetData.clear();
	Code.clear();
	m_packetData[0] = 0xAA;
	m_packetData[2] = 0xFE;
	m_packetData[3] = 0x01;
	switch (m_trainCmd)
	{
	case CMD_MOVE: //0
		Code[0] = 0;
		m_packetData[1] = 1 + 6;
		m_packetData[4] = 0x00;
		break;
	case CMD_STATE:
		m_packetData[1] = sizeof(metaData.DatastateAck) + 6;
		m_packetData[4] = 0x01;
		Code = metaData.m_Code;
		break;
	case CMD_FORMATE:
		m_packetData[1] = 1 + 6;
		m_packetData[4] = 0x02;
		Code[0] = 0x00;
		break;
	case CMD_LASERCONTROL:
		m_packetData[1] = 1 + 6;
		m_packetData[4] = 0x03;
		Code[0] = 0x00;
		break;
	case CMD_PICTUREINF:
		m_packetData[1] = 1 + 6;
		m_packetData[4] = 0x04;
		Code[0] = 0x00;
		break;
	case CMD_GPSCOORD:
		m_packetData[1] = 1 + 6;
		m_packetData[4] = 0x05;
		Code[0] = 0x00;
		break;
	case CMD_SOUNDCONTROL:
		m_packetData[1] = 1 + 6;
		m_packetData[4] = 0x06;
		Code[0] = 0x00;
		break;
	case CMD_DOWNLOADCONTROL:
		m_packetData[1] = 1 + 6;
		m_packetData[4] = 0x07;
		Code[0] = 0x00;
		break;
	default:
		break;
	}
	m_packetData += Code;
	m_packetData += 0xBB;
}

QByteArray DataPacket::getPcaket()
{
	return m_packetData;
}
