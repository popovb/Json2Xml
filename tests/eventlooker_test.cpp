#include <EventLooker.hpp>
#include <gtest/gtest.h>

TEST(eventlooker, test_01)
{
     using namespace json2xml;
     EventLooker el;
     ASSERT_TRUE(true);
}

TEST(eventlooker, test_02)
{
     using namespace json2xml;
     EventLooker el;
     ASSERT_EQ(Event::UNDEF, el.previous());
     ASSERT_EQ(Event::UNDEF, el.current());
}

TEST(eventlooker, test_03)
{
     using namespace json2xml;
     EventLooker el;
     el.set(Event::OBJECTSTART);
     ASSERT_EQ(Event::UNDEF, el.previous());
     ASSERT_EQ(Event::OBJECTSTART, el.current());
}

TEST(eventlooker, test_04)
{
     using namespace json2xml;
     EventLooker el;
     el.set(Event::OBJECTSTART);
     el.set(Event::KEY);
     ASSERT_EQ(Event::OBJECTSTART, el.previous());
     ASSERT_EQ(Event::KEY, el.current());
}
