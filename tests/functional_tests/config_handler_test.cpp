/**
 *  @file       config_handler_test.cpp
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#include "config_handler_test.h"

#include <libKitsunemimiConfig/config_handler.h>
#include <libKitsunemimiPersistence/files/text_file.h>
#include <libKitsunemimiPersistence/files/file_methods.h>

namespace Kitsunemimi
{
namespace Config
{

ConfigHandler_Test::ConfigHandler_Test()
    : Kitsunemimi::CompareTestHelper("ConfigHandler_Test")
{
    runTest();
}

/**
 * @brief runTest
 */
void
ConfigHandler_Test::runTest()
{
    std::string errorMessage = "";

    Kitsunemimi::Persistence::writeFile(m_testFilePath,
                                        getTestString(),
                                        errorMessage,
                                        true);

    // init config
    TEST_EQUAL(Kitsunemimi::Config::initConfig(m_testFilePath), true);

    TEST_EQUAL(REGISTER_STRING_CONFIG("DEFAULT", "string_val", ""), true);
    TEST_EQUAL(REGISTER_INT_CONFIG("DEFAULT", "int_val", 42), true);
    TEST_EQUAL(REGISTER_INT_CONFIG("DEFAULT", "another_int_val", 42), true);

    bool success = false;
    TEST_EQUAL(GET_STRING_CONFIG("DEFAULT", "string_val", success), "asdf.asdf");
    TEST_EQUAL(success, true);
    TEST_EQUAL(GET_INT_CONFIG("DEFAULT", "int_val", success), 2);
    TEST_EQUAL(success, true);
    TEST_EQUAL(GET_INT_CONFIG("DEFAULT", "another_int_val", success), 42);
    TEST_EQUAL(success, true);
    TEST_EQUAL(GET_STRING_CONFIG("DEFAULT", "fail", success), "");
    TEST_EQUAL(success, false);

    Kitsunemimi::Persistence::deleteFileOrDir(m_testFilePath, errorMessage);

}

/**
 * @brief ConfigHandler_Test::getTestString
 * @return
 */
const std::string
ConfigHandler_Test::getTestString()
{
    const std::string testString(
                "[DEFAULT]\n"
                "string_val = asdf.asdf\n"
                "int_val = 2\n"
                "float_val = 123.0\n"
                "string_list = a,b,c\n"
                "bool_value = true\n"
                "\n");
    return testString;
}

}
}
