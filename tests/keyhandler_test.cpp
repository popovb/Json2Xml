#include <KeyHandler.hpp>
#include <gtest/gtest.h>

/*
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
*/

TEST(keyhandler, test_03)
{
     //
     // { "key" : ...
     //    ^
     using namespace json2xml;
     KeyHandler KH(Event::OBJECTSTART);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_object();
     auto is = KH.handle(TH, PL, "TAG");
     ASSERT_EQ(1, is.size());
     Instruction i0({ InstType::OPEN, {"TAG"} });
     ASSERT_EQ(i0, is[0]);
}

TEST(keyhandler, test_04)
{
     //
     // { ...} "key": ...
     //        ^
     using namespace json2xml;
     KeyHandler KH(Event::OBJECTEND);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_object();
     auto is = KH.handle(TH, PL, "TAG2");
     ASSERT_EQ(1, is.size());
     Instruction i0({ InstType::OPEN, {"TAG2"} });
     ASSERT_EQ(i0, is[0]);
}
