#include <Json2Xml/Option.hpp>
#include <gtest/gtest.h>

TEST(option, test_01)
{
     using namespace json2xml;
     Option O;
     ASSERT_TRUE(true);
}

TEST(option, test_02)
{
     using namespace json2xml;
     Option O;
     ASSERT_EQ("json", O.getRootName());
}

TEST(option, test_03)
{
     using namespace json2xml;
     Option O;
     ASSERT_EQ("item", O.getArraysItemName());
}

TEST(option, test_04)
{
     using namespace json2xml;
     Option O;
     ASSERT_EQ("n", O.getArraysCountName());
}

TEST(option, test_05)
{
     using namespace json2xml;
     Option O("json2", "item2", "i");
     ASSERT_EQ("json2", O.getRootName());
     ASSERT_EQ("item2", O.getArraysItemName());
     ASSERT_EQ("i", O.getArraysCountName());
}
