#include <KeyHandler.hpp>
#include <gtest/gtest.h>

TEST(keyhandler, test_01)
{
     //
     // } kkk : ""
     //   ^
     using namespace json2xml;
     KeyHandler KH(Event::UNDEF);
     TagHistory TH("json");
     PlaceLooker PL;
     auto is = KH.handle(TH, PL, "kkk");
     ASSERT_EQ(1, is.size());
     Instruction i1({ InstType::OPEN, {"kkk"} });
     ASSERT_EQ(i1, is[0]);
}

TEST(keyhandler, test_02)
{
     //
     // x : 5, kkk : ""
     //        ^
     using namespace json2xml;
     KeyHandler KH(Event::VALUE);
     TagHistory TH("json");
     TH.push("x");
     PlaceLooker PL;
     auto is = KH.handle(TH, PL, "kkk");
     ASSERT_EQ(2, is.size());
     Instruction i0({ InstType::CLOSE, {"x"} });
     ASSERT_EQ(i0, is[0]);
     Instruction i1({ InstType::OPEN, {"kkk"} });
     ASSERT_EQ(i1, is[1]);
}