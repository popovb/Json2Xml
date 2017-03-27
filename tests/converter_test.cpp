#include <Json2Xml/Converter.hpp>
#include <Json2Xml/Option.hpp>
#include <fstream>
#include <gtest/gtest.h>

TEST(converter, test_01)
{
     using namespace json2xml;
     std::ifstream in("first_test_05.json");
     Converter C;
     ASSERT_TRUE(true);
}

TEST(converter, test_02)
{
     using namespace json2xml;
     std::ifstream in("first_test_05.json");
     Option O;
     Converter C(O);
     ASSERT_TRUE(true);
}
