#include "Logger.h"
Logger* Logger::pinstance_(nullptr);
std::mutex Logger::mutex_;

Logger::~Logger()
{
    if (LoggerFile.is_open())
        LoggerFile.close();
}

Logger *Logger::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if  (pinstance_ == nullptr)
        pinstance_ = new Logger();
    
    return pinstance_;
}

void Logger::writeInfoEntry(std::string function_name, std::string message)
{
    Logger* log = Logger::GetInstance();
    std::lock_guard<std::mutex> lock(log->mutex_);
    if (log->LoggerFile.is_open())
        log->LoggerFile <<  "[INFO]: " << function_name << '\t' << message << std::endl;
}

void Logger::writeWarningEntry(std::string function_name, std::string message)
{
    Logger* log = Logger::GetInstance();
    std::lock_guard<std::mutex> lock(log->mutex_);
    if (log->LoggerFile.is_open())
        log->LoggerFile <<  "[WARNING]: " << function_name << '\t' << message << std::endl;
}

void Logger::writeErrorEntry(std::string function_name, std::string message)
{
    Logger* log = Logger::GetInstance();
    std::lock_guard<std::mutex> lock(log->mutex_);
    if (log->LoggerFile.is_open())
        log->LoggerFile <<  "[ERROR]: " << function_name << '\t' << message << std::endl;
}
