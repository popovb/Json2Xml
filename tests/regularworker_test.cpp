#include <RegularWorker.hpp>
#include <Instructions.hpp>
#include <Json2Xml/Handler.hpp>
#include <gtest/gtest.h>
#include <string>

//////////////////////////////////////////////////////////////////
using String = std::string;
class HTest: public json2xml::Handler {

public:
     HTest():
	  result("") { }

public:
     virtual void Text(const String s) override {
	  result += "T";
	  result += s;
     }
     
     virtual void OpenTag(const String s) override {
	  result += "O";
	  result += s;
     }
     
     virtual void CloseTag(const String s) override {
	  result += "C";
	  result += s;
     }
     
     virtual void AttributeValue(const String s1,
				 const String s2) override {
	  result += "A";
	  result += s1;
	  result += "V";
	  result += s2;
     }

public:
     String result;  
};
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
TEST(regularworker, test_01)
{
     using namespace json2xml;
     HTest H;
     H.Text("1");
     H.OpenTag("one");
     H.CloseTag("two");
     H.AttributeValue("a","v");
     ASSERT_EQ("T1OoneCtwoAaVv", H.result);
}

TEST(regularworker, test_02)
{
     using namespace json2xml;
     HTest H;
     Instruction i1 = { InstType::OPEN,  {"open_tag"} };
     Instruction i2 = { InstType::TEXT,  {"this is text"} };
     Instruction i3 = { InstType::CLOSE, {"close_tag"} };
     Instruction i4 = { InstType::AV,    {"argument", "value"} };
     Instructions i = { i1, i2, i3, i4 };

     RegularWorker RW(H);
     RW.start(i);
     ASSERT_EQ("Oopen_tagTthis is textCclose_tagAargumentVvalue",
	       H.result);
}
//////////////////////////////////////////////////////////////////
