#include "stm32.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Stm32 w;
	w.show();
	return a.exec();
}
