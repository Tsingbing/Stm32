#include "stm32.h"

Stm32::Stm32(QWidget *parent)
	: QMainWindow(parent)
	, transactionCount(0)
	, simulateData(0)
{
	ui.setupUi(this);
	const auto infos = QSerialPortInfo::availablePorts();
	for (const QSerialPortInfo &info : infos)
		ui.serialPortComboBox->addItem(info.portName());
	connect(ui.runButton, &QPushButton::clicked, this, &Stm32::startSlave);
	connect(&thread, &SlaveThread::request, this, &Stm32::showRequest);
	connect(&thread, &SlaveThread::error, this, &Stm32::processError);
	connect(&thread, &SlaveThread::timeout, this, &Stm32::processTimeout);

	connect(ui.serialPortComboBox, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
		this, &Stm32::activateRunButton);
	connect(ui.waitRequestSpinBox, static_cast<void (QSpinBox::*)(const QString &)>(&QSpinBox::valueChanged),
		this, &Stm32::activateRunButton);
	connect(ui.responseLineEdit, &QLineEdit::textChanged, this, &Stm32::activateRunButton);

	connect(&simulateData, &Data::valueChanged, this, &Stm32::showSimulateData);
	
}

Stm32::~Stm32()
{

}

void Stm32::startSlave()
{
	ui.runButton->setEnabled(false);
	ui.statusLabel->setText(tr("Status: Running, connected to port %1.")
		.arg(ui.serialPortComboBox->currentText()));
	thread.startSlave(	ui.serialPortComboBox->currentText(),
						ui.waitRequestSpinBox->value(),
						ui.responseLineEdit->text());
}

void Stm32::showRequest(const QString & s)
{
	ui.showDataEdit->setText(m_reponseData.toHex(':'));
	m_requestData = thread.getResponseData();
	ui.responseLineEdit->setText(m_requestData.toHex(':'));

	/////////////////////////////////////////////////////////////////////��������

	if (m_requestData[0] == (char)0xaa && m_requestData[m_requestData.size() - 1] == (char)0xbb)
	{
		switch (m_requestData[4])
		{
		case CMD_MOVE: //0
			memcpy(&DataMove, m_requestData.data() + 5, m_requestData[1] - 6);//��ȡ�ֽڶ�copy���ṹ�塣
			break;
		case CMD_STATE:
			//memcpy(&DataStateAck, m_requestData.data() + 5, m_requestData[1] - 6);//��ȡ�ֽڶ�copy���ṹ�塣
			break;
		case CMD_FORMATE:

			break;
		case CMD_LASERCONTROL:

			break;
		case CMD_PICTUREINF:

			break;
		case CMD_GPSCOORD:

			break;
		case CMD_SOUNDCONTROL:

			break;
		case CMD_DOWNLOADCONTROL:

			break;
		default:
			break;
		}
	}
	/////////////////////////////////////////////////////////////////////
	ui.trafficLabel->setText(tr("Traffic, transaction #%1:")
		.arg(++transactionCount));

	ui.trafficLabel2->setText(tr(
		"\n\r-DataMove.Speed: %1"
		"\n\r-DataMove.Direction: %2"
		"\n\r-DataMove.lightpower: %3"
		"\n\r-DataMove.Deepset: %4"
		"\n\r-DataMove.Roll: %5"
		"\n\r-DataMove.Yaw: %6"
	)
		.arg((int)(DataMove.Speed		))
		.arg((int)(DataMove.Direction	))
		.arg((int)(DataMove.lightpower  )) 
		.arg((int)(DataMove.Deepset		))
		.arg((int)(DataMove.Roll		))	
		.arg((int)(DataMove.Yaw			))
	);

}

void Stm32::processError(const QString &s)
{
	activateRunButton();
	ui.statusLabel->setText(tr("Status: Not running, %1.").arg(s));
	ui.trafficLabel->setText(tr("No traffic."));
}

void Stm32::processTimeout(const QString &s)
{
	ui.statusLabel->setText(tr("Status: Running, %1.").arg(s));
	ui.trafficLabel->setText(tr("No traffic."));
}
void Stm32::activateRunButton()
{
	ui.runButton->setEnabled(true);
}

void Stm32::showSimulateData()
{
	ui.showDataLabel->setText(tr(
		"\n\r-DatastateAck.speed: %1"
		"\n\r-DatastateAck.Direction: %2"
		"\n\r-DatastateAck.Power: %3"
		"\n\r-DatastateAck.Temp: %4"
		"\n\r-DatastateAck.Hum: %5"
		"\n\r-DatastateAck.Roll: %6"
		"\n\r-DatastateAck.pitch: %7"
		"\n\r-DatastateAck.Yaw: %8"
		"\n\r-DatastateAck.pointID: %9"
		"\n\r-DatastateAck.v: %10"
		"\n\r-DatastateAck.NowDeepth: %11"
		"\n\r-DatastateAck.point.x: %12"
		"\n\r-DatastateAck.point.y: %13"
	    )
		.arg((int)(simulateData.DatastateAck.speed)	  )
		.arg((int)(simulateData.DatastateAck.Direction))
		.arg((int)(simulateData.DatastateAck.Power)	  )
		.arg((int)(simulateData.DatastateAck.Temp)	  )
		.arg((int)(simulateData.DatastateAck.Hum)	  )
		.arg((int)(simulateData.DatastateAck.Roll)	  )
		.arg((int)(simulateData.DatastateAck.pitch)	  )
		.arg((int)(simulateData.DatastateAck.Yaw)	  )
		.arg((int)(simulateData.DatastateAck.pointID)  )
		.arg((int)(simulateData.DatastateAck.v)		  )
		.arg((int)(simulateData.DatastateAck.NowDeepth))
		.arg((int)(simulateData.DatastateAck.point.x)  )
		.arg((int)(simulateData.DatastateAck.point.y)  )
	   );

	m_dataPacket.setPacket(simulateData, CMD_STATE);
	m_reponseData = m_dataPacket.getPacket();
	thread.setResponseData(m_reponseData);
}


