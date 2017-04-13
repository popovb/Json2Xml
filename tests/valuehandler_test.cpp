#include <ValueHandler.hpp>
#include <gtest/gtest.h>

TEST(valuehandler, test_01)
{
     //
     // { "value"...
     //   ^
     using namespace json2xml;
     Option O;
     ValueHandler VH(O, Event::OBJECTSTART);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_object();
     auto is = VH.handle(TH, PL, "001");
     ASSERT_EQ(3, is.size());
     Instruction i0({ InstType::OPEN, {"json"} });
     Instruction i1({ InstType::TEXT, {"001"} });
     Instruction i2({ InstType::CLOSE, {"json"} });
     ASSERT_EQ(i0, is[0]);
     ASSERT_EQ(i1, is[1]);
     ASSERT_EQ(i2, is[2]);
}

TEST(valuehandler, test_02)
{
     //
     // { ...} "value"...
     //        ^
     using namespace json2xml;
     Option O;
     ValueHandler VH(O, Event::OBJECTEND);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_object();
     auto is = VH.handle(TH, PL, "002");
     ASSERT_EQ(3, is.size());
     Instruction i0({ InstType::OPEN, {"json"} });
     Instruction i1({ InstType::TEXT, {"002"} });
     Instruction i2({ InstType::CLOSE, {"json"} });
     ASSERT_EQ(i0, is[0]);
     ASSERT_EQ(i1, is[1]);
     ASSERT_EQ(i2, is[2]);
}
