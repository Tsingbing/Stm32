#ifndef SHARKSIMULATOR_H
#define SHARKSIMULATOR_H

#include <QtWidgets/QMainWindow>
#include "ui_sharksimulator.h"

class SharkSimulator : public QMainWindow
{
	Q_OBJECT

public:
	SharkSimulator(QWidget *parent = 0);
	~SharkSimulator();

private:
	Ui::SharkSimulatorClass ui;
};

#endif // SHARKSIMULATOR_H
