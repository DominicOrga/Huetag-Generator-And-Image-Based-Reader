#include <QtWidgets/QApplication>
#include <windows.h>
#include <ctime>

#include "huetagreaderwindow.h"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"

static int a;

int main(int argc, char *argv[])
{
	time_t t;
	time(&t);
	srand(t);

	QApplication a(argc, argv);
	huetagreaderwindow w;

	w.show();

	return a.exec();
}
