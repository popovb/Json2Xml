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
     ConvertHandler CH(NH, O);
     ASSERT_TRUE(true);
}

////
class Event {

public:
     Event(std::string one = "",
	   std::string two = "",
	   std::string three = ""):
	  type(one),
	  arg1(two),
	  arg2(three) { }

     std::string type;
     std::string arg1;
     std::string arg2;
};

bool operator==(const Event& l, const Event& r) {
     if (l.type == r.type)
	  if (l.arg1 == r.arg1)
	       if (l.arg2 == r.arg2)
		    return true;
     return false;
}

bool operator!=(const Event& l, const Event& r) {
     if (l.type != r.type) return true;
     if (l.arg1 != r.arg1) return true;
     if (l.arg2 != r.arg2) return true;
     return false;
}

class TEXT: public Event {
public:
     TEXT(std::string s):
	  Event("TEXT", s ) { }
};

class OPEN: public Event {
public:
     OPEN(std::string s):
	  Event("OPEN", s ) { }
};

class CLOSE: public Event {
public:
     CLOSE(std::string s):
	  Event("CLOSE", s ) { }
};

class AV: public Event {
public:
     AV(std::string s1,
	std::string s2):
	  Event("AV", s1, s2 ) { }
};
////

TEST(converthandler, test_02)
{
     using namespace json2xml;
     ASSERT_EQ(TEXT("1"), TEXT("1"));
}

TEST(converthandler, test_03)
{
     using namespace json2xml;
     ASSERT_NE(TEXT("1"), TEXT("2"));
}

TEST(converthandler, test_04)
{
     using namespace json2xml;
     ASSERT_NE(TEXT("1"), OPEN("Open"));
}

TEST(converthandler, test_05)
{
     using namespace json2xml;
     ASSERT_EQ(OPEN("Open"), OPEN("Open"));
}
