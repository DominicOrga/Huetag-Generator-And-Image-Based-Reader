#include <iostream>
#include "logger.h"
#include "qfile.h"
#include "qtextstream.h"
#include "qstring.h"
#include "qstandardpaths.h"
#include "qdir.h"
#include "windows.h"
#include <shellapi.h>
#pragma comment(lib,"shell32.lib") 

logger::logger() {
	QString location = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
	
	if (!QDir(location).exists()) {
		QDir().mkdir(location);
	}

	location.append("/huetag-log.txt");

	_filePath = new QString(location);

	open();
	close();
}

void logger::open() {
	close();

	_logFile = new QFile(*_filePath);

	if (_logFile->open(QIODevice::ReadWrite | QIODevice::Text)) {
		_logFile->resize(0);
		_textStream = new QTextStream(_logFile);
	}
}

void logger::close() {
	if (_logFile) {
		_logFile->close();

		delete _logFile;
		delete _textStream;

		_logFile = NULL;
		_textStream = NULL;
	}
}

void logger::openLogFile() {
	ShellExecute(NULL, L"OPEN", _filePath->toStdWString().c_str(), NULL, NULL, 1);
}

void logger::write(QString text) {
	if (_logFile->isOpen())
		*_textStream << text;
}

void logger::writeln(QString text) {
	if (_logFile->isOpen())
		*_textStream << text << "\n";
}


