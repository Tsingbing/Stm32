#include "sharksimulator.h"
#include "dialog.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	Dialog dialog;
	dialog.show();
	return app.exec();
}
