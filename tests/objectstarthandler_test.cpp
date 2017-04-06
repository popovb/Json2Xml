#include <ObjectStartHandler.hpp>
#include <gtest/gtest.h>

TEST(objectstarthandler, test_01)
{
     //
     // { }
     // ^
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
}

TEST(objectstarthandler, test_02)
{
     //
     // { { } }
     //   ^
     using namespace json2xml;
     Option O;
     ObjectStartHandler OSH(O, Event::OBJECTSTART);
     TagHistory TH("json");
     PlaceLooker PL;
     PL++;
     PL.set_object();
     PL++;
     PL.set_object();
     auto is = OSH.handle(TH, PL);
     ASSERT_EQ(1, is.size());
     Instruction i1({ InstType::OPEN, {"json"} });
     ASSERT_EQ(i1, is[0]);
}
