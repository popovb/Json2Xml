#include <AVBuilder.hpp>
#include <gtest/gtest.h>

TEST(avbuilder, test_01)
{
     using namespace json2xml;
     AVBuilder avb;
}

TEST(avbuilder, test_02)
{
     using namespace json2xml;
     AVBuilder avb;
     ASSERT_FALSE(avb);
}

TEST(avbuilder, test_03)
{
     using namespace json2xml;
     AVBuilder avb;
     avb.set("one", "1");
     ASSERT_TRUE(avb);
}

TEST(avbuilder, test_04)
{
     using namespace json2xml;
     AVBuilder avb;
     avb.set("one", "1");
     ASSERT_TRUE(avb);
     avb.clear();
     ASSERT_FALSE(avb);
}

TEST(avbuilder, test_05)
{
     using namespace json2xml;
     AVBuilder avb;
     avb.set("one", "1");
     ASSERT_EQ("one=\"1\"", avb.get());
     avb.set("two", "2");
     ASSERT_EQ("one=\"1\" two=\"2\"", avb.get());
     avb.set("three", "3");
     ASSERT_EQ("one=\"1\" two=\"2\" three=\"3\"", avb.get());
}
