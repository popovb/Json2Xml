#include <Json2Xml/NullHandler.hpp>
#include <gtest/gtest.h>

TEST(handler, test_01)
{
     using namespace json2xml;
     NullHandler NH;
     ASSERT_TRUE(true);
}

TEST(handler, test_02)
{
     using namespace json2xml;
     NullHandler NH;
     NH.Text("test");
     NH.OpenTag("test");
     NH.CloseTag("test");
     NH.AttributeValue("test", "test");
     ASSERT_TRUE(true);
}
