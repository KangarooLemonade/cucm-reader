#include <QApplication>

#include "testoutputdialog.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	TestOutputDialog *test = new TestOutputDialog;
	test->show();
	return app.exec();
}
