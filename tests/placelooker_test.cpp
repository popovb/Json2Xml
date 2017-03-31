#include <PlaceLooker.hpp>
#include <gtest/gtest.h>

TEST(placelooker, test_01)
{
     using namespace json2xml;
     PlaceLooker pl;
     ASSERT_TRUE(true);
}

TEST(placelooker, test_02)
{
     using namespace json2xml;
     PlaceLooker pl;
     pl.set_object();
     pl.set_array();
     ASSERT_TRUE(true);
}

TEST(placelooker, test_03)
{
     using namespace json2xml;
     PlaceLooker pl;
     pl.set_object();
     pl.set_array();
     ASSERT_EQ(true, pl.is_array());
     ASSERT_EQ(false, pl.is_object());
     pl.release();
     ASSERT_EQ(false, pl.is_array());
     ASSERT_EQ(true, pl.is_object());
     pl.release();
     ASSERT_EQ(false, pl.is_array());
     ASSERT_EQ(false, pl.is_object());
     pl.release();
}

TEST(placelooker, test_04)
{
     using namespace json2xml;
     PlaceLooker pl;
     ASSERT_EQ(0, pl.get_count());
     pl++;
     ASSERT_EQ(0, pl.get_count());
     pl.set_object();
     ASSERT_EQ(0, pl.get_count());
     pl++;
     ASSERT_EQ(1, pl.get_count());
     pl.set_array();
     ASSERT_EQ(0, pl.get_count());
     pl++;
     pl++;
     pl++;
     ASSERT_EQ(3, pl.get_count());
     pl.release();
     ASSERT_EQ(1, pl.get_count());
     pl.release();
     ASSERT_EQ(0, pl.get_count());
     pl.release();
     ASSERT_EQ(0, pl.get_count());
}
