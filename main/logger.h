#pragma once

class QFile;
class QTextStream;
class QString;

class logger {

public:
	logger();

	void open();
	void close();

	void write(QString text);
	void writeln(QString text);
	void openLogFile();

private:
	QFile* _logFile;
	QTextStream* _textStream;
	QString* _filePath;
};