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
     ASSERT_EQ("Json", O.getRootName());
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
