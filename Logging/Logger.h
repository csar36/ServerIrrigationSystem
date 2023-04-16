//@Singleton

#ifndef __LOGGER_H__
#define __LOGGER_H__
#include <iostream>
#include <mutex>
#include <fstream>

class Logger
{

    private:
        static Logger* pinstance_;        

    protected:
        Logger()
        {
        	std::string path = "";
            std::string filePath = path + "ServerLog.log";
            std::cout << filePath << std::endl;
            LoggerFile.open(filePath, std::ios::app);
        }

        static Logger* Logger_;
        ~Logger();

    public:
        Logger(Logger &other) = delete;

        void operator=(const Logger&) = delete;
        static std::mutex mutex_;
        static Logger *GetInstance();
        void writeInfoEntry(std::string function_name, std::string message);
        void writeWarningEntry(std::string function_name, std::string message);
        void writeErrorEntry(std::string function_name, std::string message);
        std::ofstream LoggerFile;
};

#endif

