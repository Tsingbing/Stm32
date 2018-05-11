#ifndef STM32_H
#define STM32_H

#include <QtWidgets/QMainWindow>
#include "ui_stm32.h"

class Stm32 : public QMainWindow
{
	Q_OBJECT

public:
	Stm32(QWidget *parent = 0);
	~Stm32();

private:
	Ui::Stm32Class ui;
};

#endif // STM32_H
