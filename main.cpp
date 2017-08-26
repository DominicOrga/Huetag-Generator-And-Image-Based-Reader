#include <QtWidgets/QApplication>
#include <qfiledialog.h>
#include <windows.h>

#include "qttest.h"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	qtTest w;
	w.show();

	return a.exec();
}
