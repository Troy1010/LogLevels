#pragma once
#include "Logging.h"

// I tried adding a test project, but adding LogLevels as a dependant project didn't include everything it needed, and I didn't want to investigate further.
// As a duct-tape solution, I'll be putting tests here.
class QuasiTests
{
public:
    void runTests()
    {
        logz("QuasiTests.runTests()`Open")
        std::string testName = "Test 1";
        if (!InternalShouldLog(22, LogLevel::DEBUGZ))
        {
            throw std::runtime_error(testName + " failed");
        }
        logz(testName + " passed")
        testName = "Test 2";
        InternalSetLogLevel(22, LogLevel::WARNING);
        if (InternalShouldLog(22, LogLevel::DEBUGZ))
        {
            throw std::runtime_error(testName + " failed");
        }
        logz(testName + " passed")
        testName = "Test 3";
        InternalSetLogLevel(22, LogLevel::WARNING);
        if (!InternalShouldLog(22, LogLevel::INFO))
        {
            throw std::runtime_error(testName + " failed");
        }
        logz(testName + " passed")
        logz("QuasiTests.runTests()`Close")
    }
};
