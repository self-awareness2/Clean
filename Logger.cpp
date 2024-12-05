#include "Logger.h"

lg::Logger& lg::Logger::instance()
{
	static Logger instance;
	return instance;
}
lg::Logger::Logger( ):
	logger(nullptr), consoleAppender(nullptr), fileAppender(nullptr), layout(nullptr), isinited(false)
{
}

lg::Logger::~Logger()
{
	if (consoleAppender) delete consoleAppender;
	if (fileAppender) delete fileAppender;
	if (layout) delete layout;
}

QString lg::Logger::getTime()
{
	int year = today.year();
	int  month = today.month();
	int day = today.day();
	return QString::number(year) + "-" + QString::number(month).rightJustified(2, '0') + "-" + QString::number(day).rightJustified(2, '0');
}

void lg::Logger::init(QString logName) {
	if (isinited) return;
	today = QDate::currentDate();
	logger = Log4Qt::Logger::logger(logName);
	consoleAppender = new Log4Qt::ConsoleAppender();
	fileAppender = new Log4Qt::FileAppender();
	layout = new Log4Qt::PatternLayout();

	logger->setLevel(Log4Qt::Level::DEBUG_INT);
	logger->addAppender(consoleAppender);

	QString filename;
	filename += "./logs/";
	filename += getTime();
	filename += ".log";
	fileAppender->setFile(filename);
	fileAppender->setAppendFile(true);
	logger->addAppender(fileAppender);

	layout->setConversionPattern("%d{yyyy-MM-dd hh:mm::ss} [%t] {%L} %-5p %c - %m%n");
	consoleAppender->setLayout(layout);
	fileAppender->setLayout(layout);

	consoleAppender->activateOptions();
	consoleAppender->setThreshold(Log4Qt::Level::DEBUG_INT);

	fileAppender->activateOptions();
	fileAppender->setThreshold(Log4Qt::Level::DEBUG_INT);

	isinited = true;
}

void lg::Logger::Debug(const char* message)
{
	QString qstr = QString::fromUtf8(message);
	QByteArray asciiData = qstr.toLatin1();
	logger->debug(asciiData.constData());
}
void lg::Logger::Info(const char* message)
{
	QString qstr = QString::fromUtf8(message);
	QByteArray asciiData = qstr.toLatin1();
	logger->info(asciiData.constData());
}
void lg::Logger::Warn(const char* message)
{
	QString qstr = QString::fromUtf8(message);
	QByteArray asciiData = qstr.toLatin1();
	logger->warn(asciiData.constData());
}
void lg::Logger::Error(const char* message) {
	QString qstr = QString::fromUtf8(message);
	QByteArray asciiData = qstr.toLatin1();
	logger->error(asciiData.constData());
}