
#include "customloglevel.h"
#include <log4cplus/consoleappender.h>
#include <iomanip>
#include <iostream>


using namespace std;
using namespace log4cplus;

// Forward Declarations
void writeLogMessage();


int
main()
{
    cout << "Entering main()..." << endl;
    {
    SharedAppenderPtr append_1(new ConsoleAppender());
    append_1->setName("First");
//    append_1->setLayout( std::auto_ptr<Layout>(new TTCCLayout()) );
    cout << "Getting root logger...DONE" << endl;
    Logger::getRoot().addAppender(append_1);

    Logger root = Logger::getRoot();
    Logger test = Logger::getInstance("test");
    Logger subTest = Logger::getInstance("test.subtest");
    LogLevelManager& llm = getLogLevelManager();

    LOG4CPLUS_FATAL(root, "root: " << llm.toString(root.getChainedLogLevel()))
    LOG4CPLUS_FATAL(root, "test: " << llm.toString(test.getChainedLogLevel()))
    LOG4CPLUS_FATAL(root, "test.subtest: " << llm.toString(subTest.getChainedLogLevel()))

    LOG4CPLUS_FATAL(root, "\nSetting test.subtest to WARN")
    subTest.setLogLevel(WARN_LOG_LEVEL);
    LOG4CPLUS_FATAL(root, "root: " << llm.toString(root.getChainedLogLevel()))
    LOG4CPLUS_FATAL(root, "test: " << llm.toString(test.getChainedLogLevel()))
    LOG4CPLUS_FATAL(root, "test.subtest: " << llm.toString(subTest.getChainedLogLevel()))

    LOG4CPLUS_FATAL(root, "\nSetting test to CRITICAL")
    test.setLogLevel(CRITICAL_LOG_LEVEL);
    LOG4CPLUS_FATAL(root, "root: " << llm.toString(root.getChainedLogLevel()))
    LOG4CPLUS_FATAL(root, "test: " << llm.toString(test.getChainedLogLevel()))
    LOG4CPLUS_FATAL(root, "test.subtest: " << llm.toString(subTest.getChainedLogLevel()))

    LOG4CPLUS_FATAL(root, "\nSetting test.subtest to NOT_SET_LOG_LEVEL")
    subTest.setLogLevel(NOT_SET_LOG_LEVEL);
    LOG4CPLUS_FATAL(root, "root: " << llm.toString(root.getChainedLogLevel()))
    LOG4CPLUS_FATAL(root, "test: " << llm.toString(test.getChainedLogLevel()))
    LOG4CPLUS_FATAL(root, "test.subtest: " << llm.toString(subTest.getChainedLogLevel()) << '\n')

    writeLogMessage();
    cout << "Returned from writeLogMessage()..." << endl;
    }
    cout << "REALLY exiting main()..." << endl;

    return 0;
}


