#include <iomanip>
#include "../log4cplus/include/log4cplus/logger.h"
#include "../log4cplus/include/log4cplus/configurator.h"

using namespace log4cplus;

int
main()
{
    BasicConfigurator config;
    config.configure();

    Logger logger = Logger::getInstance("main");
    LOG4CPLUS_WARN(logger, "Hello, World!");
    return 0;
}

