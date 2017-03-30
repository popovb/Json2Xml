#include "ConvertHandler.hpp"
#include <Json2Xml/NullHandler.hpp>
#include <Json2Xml/Option.hpp>
#include "SimpleJson/Handler.hpp"
#include <gtest/gtest.h>
#include <vector>

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

////
using String = std::string;
class TESTHANDLER: public json2xml::Handler {
public:
     std::vector<Event> events;

     virtual void Text(const String s) {
	  events.push_back(TEXT(s)); }
     virtual void OpenTag(const String s) {
	  events.push_back(OPEN(s)); }
     virtual void CloseTag(const String s) {
	  events.push_back(CLOSE(s)); }
     virtual void AttributeValue(const String s1,
				 const String s2) {
	  events.push_back(AV(s1, s2)); }
};
////

TEST(converthandler, test_06)
{
     using namespace json2xml;
     Option O;
     TESTHANDLER TH;
     ConvertHandler CH(TH, O);
     ASSERT_TRUE(true);
}

TEST(converthandler, test_07)
{
     using namespace json2xml;
     Option O;
     TESTHANDLER TH;
     ConvertHandler CH(TH, O);
     ///
     CH.ObjectStart();
     CH.ObjectEnd();
     ///
     for (size_t i = 0; i < TH.events.size(); i++) {
	  switch (i) {
	  case 0: {
	       ASSERT_EQ(OPEN("json"), TH.events[i]);
	       break;
	  }
	  case 1: {
	       ASSERT_EQ(CLOSE("json"), TH.events[i]);
	       break;
	  }
	  default:
	       ASSERT_TRUE(false);
	  }
     }
     ASSERT_TRUE(true);
}

TEST(converthandler, test_08)
{
     using namespace json2xml;
     Option O;
     TESTHANDLER TH;
     ConvertHandler CH(TH, O);
     ///
     CH.ObjectStart();
     CH.Key("x");
     CH.Value("6");
     CH.ObjectEnd();
     ///
     ASSERT_EQ(5, TH.events.size());
     for (size_t i = 0; i < TH.events.size(); i++) {
	  switch (i) {
	  case 0: {
	       ASSERT_EQ(OPEN("json"), TH.events[i]);
	       break;
	  }
	  case 1: {
	       ASSERT_EQ(OPEN("x"), TH.events[i]);
	       break;
	  }
	  case 2: {
	       ASSERT_EQ(TEXT("6"), TH.events[i]);
	       break;
	  }
	  case 3: {
	       ASSERT_EQ(CLOSE("x"), TH.events[i]);
	       break;
	  }
	  case 4: {
	       ASSERT_EQ(CLOSE("json"), TH.events[i]);
	       break;
	  }
	  default:
	       ASSERT_TRUE(false);
	  }
     }
     ASSERT_TRUE(true);
}
