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
     Option O;
     KeyHandler KH(O, Event::OBJECTSTART);
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
     Option O;
     KeyHandler KH(O, Event::OBJECTEND);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_object();
     auto is = KH.handle(TH, PL, "TAG2");
     ASSERT_EQ(1, is.size());
     Instruction i0({ InstType::OPEN, {"TAG2"} });
     ASSERT_EQ(i0, is[0]);
}

TEST(keyhandler, test_05)
{
     //
     // [ ...} "key": ...
     //        ^
     using namespace json2xml;
     Option O;
     KeyHandler KH(O, Event::OBJECTEND);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_array();
     PL++;
     PL++;
     auto is = KH.handle(TH, PL, "TAG3");
     ASSERT_EQ(3, is.size());
     Instruction i0({ InstType::OPEN, {"item"} });
     ASSERT_EQ(i0, is[0]);
     Instruction i1({ InstType::AV, {"n", "2"} });
     ASSERT_EQ(i1, is[1]);
     Instruction i2({ InstType::AV, {"name", "TAG3"} });
     ASSERT_EQ(i2, is[2]);
}

TEST(keyhandler, test_06)
{
     //
     // [ ... "key": ...
     //        ^
     using namespace json2xml;
     Option O;
     KeyHandler KH(O, Event::ARRAYSTART);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_array();
     PL++;
     PL++;
     PL++;
     auto is = KH.handle(TH, PL, "TAG4");
     ASSERT_EQ(3, is.size());
     Instruction i0({ InstType::OPEN, {"item"} });
     ASSERT_EQ(i0, is[0]);
     Instruction i1({ InstType::AV, {"n", "3"} });
     ASSERT_EQ(i1, is[1]);
     Instruction i2({ InstType::AV, {"name", "TAG4"} });
     ASSERT_EQ(i2, is[2]);
}

TEST(keyhandler, test_07)
{
     //
     // { ...] "key": ...
     //        ^
     using namespace json2xml;
     Option O;
     KeyHandler KH(O, Event::ARRAYEND);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_object();
     PL++;
     PL++;
     PL++;
     auto is = KH.handle(TH, PL, "TAG5");
     ASSERT_EQ(1, is.size());
     Instruction i0({ InstType::OPEN, {"TAG5"} });
     ASSERT_EQ(i0, is[0]);
}

TEST(keyhandler, test_08)
{
     //
     // [ ...] "key": ...
     //        ^
     using namespace json2xml;
     Option O;
     KeyHandler KH(O, Event::ARRAYEND);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_array();
     PL++;
     auto is = KH.handle(TH, PL, "TAG6");
     ASSERT_EQ(3, is.size());
     Instruction i0({ InstType::OPEN, {"item"} });
     ASSERT_EQ(i0, is[0]);
     Instruction i1({ InstType::AV, {"n", "1"} });
     ASSERT_EQ(i1, is[1]);
     Instruction i2({ InstType::AV, {"name", "TAG6"} });
     ASSERT_EQ(i2, is[2]);
}

TEST(keyhandler, test_09)
{
     //
     // { ..."value", "key": ...
     //               ^
     using namespace json2xml;
     Option O;
     KeyHandler KH(O, Event::VALUE);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_object();
     PL++;
     auto is = KH.handle(TH, PL, "TAG7");
     ASSERT_EQ(1, is.size());
     Instruction i0({ InstType::OPEN, {"TAG7"} });
     ASSERT_EQ(i0, is[0]);
}

TEST(keyhandler, test_10)
{
     //
     // [ ..."value", "key": ...
     //               ^
     using namespace json2xml;
     Option O;
     KeyHandler KH(O, Event::VALUE);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_array();
     PL++;
     PL++;
     PL++;
     auto is = KH.handle(TH, PL, "TAG8");
     ASSERT_EQ(3, is.size());
     Instruction i0({ InstType::OPEN, {"item"} });
     ASSERT_EQ(i0, is[0]);
     Instruction i1({ InstType::AV, {"n", "3"} });
     ASSERT_EQ(i1, is[1]);
     Instruction i2({ InstType::AV, {"name", "TAG8"} });
     ASSERT_EQ(i2, is[2]);

}
