#include <TagHistory.hpp>
#include <gtest/gtest.h>

TEST(taghistory, test_01)
{
     using namespace json2xml;
     TagHistory tg("json");
     ASSERT_TRUE(true);
}

TEST(taghistory, test_02)
{
     using namespace json2xml;
     TagHistory tg("json");
     ASSERT_EQ("json", tg.pop());
     ASSERT_EQ("json", tg.pop());
}

TEST(taghistory, test_03)
{
     using namespace json2xml;
     TagHistory tg("json");
     tg.push("one");
     tg.push("two");
     ASSERT_EQ("two", tg.pop());
     ASSERT_EQ("one", tg.pop());
     ASSERT_EQ("json", tg.pop());
     ASSERT_EQ("json", tg.pop());
}
