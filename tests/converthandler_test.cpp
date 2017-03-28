#include "ConvertHandler.hpp"
#include <Json2Xml/NullHandler.hpp>
#include <Json2Xml/Option.hpp>
#include "SimpleJson/Handler.hpp"
#include <gtest/gtest.h>

TEST(converthandler, test_01)
{
     using namespace json2xml;
     Option O;
     NullHandler NH;
     //simple_json::Handler H;
     ConvertHandler CH(NH, O);
     ASSERT_TRUE(true);
}
