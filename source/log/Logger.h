#pragma once

#include <log4qt/log4qt.h>
#include <log4qt/logger.h>
#include <log4qt/consoleappender.h>
#include<log4qt/patternlayout.h>
#include<log4qt/logmanager.h>
#include <log4qt/fileappender.h>
#include <log4qt/propertyconfigurator.h>
#include <qdatetime.h>
#include <memory>

namespace lg {
	class Logger
	{
	private:
		Logger( );
		~Logger();
		Logger(const Logger&) = delete; // 禁用拷贝构造
		Logger& operator=(const Logger&) = delete; // 禁用赋值运算符
		QString getTime();
		Log4Qt::Logger *logger;
		Log4Qt::ConsoleAppender* consoleAppender;
		Log4Qt::FileAppender* fileAppender;
		QDate today;
		QString filename;
		Log4Qt::PatternLayout* layout;  //交给appder后无需手动释放
		bool  isinited;
	public:
		static Logger& instance();
		void init(QString logName);
		void Debug(const char* message);
		void Info(const char* message);
		void Warn(const char* message);
		void Error(const char* message);
	};

}

