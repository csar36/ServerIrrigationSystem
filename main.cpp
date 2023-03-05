#include "Logging/Logger.h"


int main()
{
	Logger* myLogger = Logger::GetInstance();
	myLogger->writeInfoEntry("main", "Hallo");

	return 0;
}
