#include <ObjectStartHandler.hpp>
#include <ObjectEndHandler.hpp>
#include <gtest/gtest.h>

TEST(objectendhandler, test_01)
{
     //
     // { }
     //   ^
     using namespace json2xml;
     Option O;
     ObjectStartHandler OSH(O, Event::UNDEF);
     TagHistory TH("json");
     PlaceLooker PL;
     PL++;
     PL.set_object();
     auto is = OSH.handle(TH, PL);
     ASSERT_EQ(1, is.size());
     Instruction i1({ InstType::OPEN, {"Json"} });
     ASSERT_EQ(i1, is[0]);
     ObjectEndHandler OEH(Event::OBJECTSTART);
     //
     //
     //
     is = OEH.handle(TH, PL);
     ASSERT_EQ(1, is.size());
     Instruction i2({ InstType::CLOSE, {"Json"} });
     ASSERT_EQ(i2, is[0]);
}
