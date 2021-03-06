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

TEST(valuehandler, test_03)
{
     //
     // [ ...} "value"...
     //        ^
     using namespace json2xml;
     Option O;
     ValueHandler VH(O, Event::OBJECTEND);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_array();
     PL++;
     PL++;
     auto is = VH.handle(TH, PL, "003");
     ASSERT_EQ(4, is.size());
     Instruction i0({ InstType::OPEN, {"item"} });
     Instruction i1({ InstType::AV, {"n", "2"} });
     Instruction i2({ InstType::TEXT, {"003"} });
     Instruction i3({ InstType::CLOSE, {"item"} });
     ASSERT_EQ(i0, is[0]);
     ASSERT_EQ(i1, is[1]);
     ASSERT_EQ(i2, is[2]);
     ASSERT_EQ(i3, is[3]);
}

TEST(valuehandler, test_04)
{
     //
     // [ ... "value"...
     //        ^
     using namespace json2xml;
     Option O;
     ValueHandler VH(O, Event::ARRAYSTART);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_array();
     PL++;
     PL++;
     PL++;
     auto is = VH.handle(TH, PL, "004");
     ASSERT_EQ(4, is.size());
     Instruction i0({ InstType::OPEN, {"item"} });
     Instruction i1({ InstType::AV, {"n", "3"} });
     Instruction i2({ InstType::TEXT, {"004"} });
     Instruction i3({ InstType::CLOSE, {"item"} });
     ASSERT_EQ(i0, is[0]);
     ASSERT_EQ(i1, is[1]);
     ASSERT_EQ(i2, is[2]);
     ASSERT_EQ(i3, is[3]);
}

TEST(valuehandler, test_05)
{
     //
     // { ...] "value"...
     //        ^
     using namespace json2xml;
     Option O;
     ValueHandler VH(O, Event::ARRAYEND);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_object();
     PL++;
     PL++;
     PL++;
     auto is = VH.handle(TH, PL, "005");
     ASSERT_EQ(3, is.size());
     Instruction i0({ InstType::OPEN, {"json"} });
     Instruction i1({ InstType::TEXT, {"005"} });
     Instruction i2({ InstType::CLOSE, {"json"} });
     ASSERT_EQ(i0, is[0]);
     ASSERT_EQ(i1, is[1]);
     ASSERT_EQ(i2, is[2]);
}

TEST(valuehandler, test_06)
{
     //
     // [ ...] "value"...
     //        ^
     using namespace json2xml;
     Option O;
     ValueHandler VH(O, Event::ARRAYEND);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_array();
     PL++;
     PL++;
     PL++;
     PL++;
     auto is = VH.handle(TH, PL, "006");
     ASSERT_EQ(4, is.size());
     Instruction i0({ InstType::OPEN, {"item"} });
     Instruction i1({ InstType::AV, {"n", "4"} });
     Instruction i2({ InstType::TEXT, {"006"} });
     Instruction i3({ InstType::CLOSE, {"item"} });
     ASSERT_EQ(i0, is[0]);
     ASSERT_EQ(i1, is[1]);
     ASSERT_EQ(i2, is[2]);
     ASSERT_EQ(i3, is[3]);
}

TEST(valuehandler, test_07)
{
     //
     // { "key" : "value"...
     //           ^
     using namespace json2xml;
     Option O;
     ValueHandler VH(O, Event::KEY);
     TagHistory TH("json");
     TH.push("key07");
     PlaceLooker PL;
     PL.set_object();
     PL++;
     PL++;
     PL++;
     PL++;
     auto is = VH.handle(TH, PL, "007");
     ASSERT_EQ(2, is.size());
     Instruction i2({ InstType::TEXT, {"007"} });
     Instruction i3({ InstType::CLOSE, {"key07"} });
     ASSERT_EQ(i2, is[0]);
     ASSERT_EQ(i3, is[1]);
}

TEST(valuehandler, test_08)
{
     //
     // [ "key" : "value"...
     //           ^
     using namespace json2xml;
     Option O;
     ValueHandler VH(O, Event::KEY);
     TagHistory TH("json");
     TH.push("item");
     PlaceLooker PL;
     PL.set_array();
     PL++;
     PL++;
     PL++;
     PL++;
     auto is = VH.handle(TH, PL, "008");
     ASSERT_EQ(2, is.size());
     Instruction i2({ InstType::TEXT, {"008"} });
     Instruction i3({ InstType::CLOSE, {"item"} });
     ASSERT_EQ(i2, is[0]);
     ASSERT_EQ(i3, is[1]);
}

TEST(valuehandler, test_09)
{
     //
     // { "value" "value"
     //           ^
     using namespace json2xml;
     Option O;
     ValueHandler VH(O, Event::VALUE);
     TagHistory TH("json");
     TH.push("item");
     PlaceLooker PL;
     PL.set_object();
     PL++;
     PL++;
     PL++;
     PL++;
     auto is = VH.handle(TH, PL, "009");
     ASSERT_EQ(3, is.size());
     Instruction i0({ InstType::OPEN, {"json"} });
     Instruction i1({ InstType::TEXT, {"009"} });
     Instruction i2({ InstType::CLOSE, {"json"} });
     ASSERT_EQ(i0, is[0]);
     ASSERT_EQ(i1, is[1]);
     ASSERT_EQ(i2, is[2]);
}

TEST(valuehandler, test_10)
{
     //
     // [ "value" "value"
     //           ^
     using namespace json2xml;
     Option O;
     ValueHandler VH(O, Event::VALUE);
     TagHistory TH("json");
     TH.push("item");
     PlaceLooker PL;
     PL.set_array();
     PL++;
     PL++;
     PL++;
     PL++;
     PL++;
     auto is = VH.handle(TH, PL, "010");
     ASSERT_EQ(4, is.size());
     Instruction i0({ InstType::OPEN, {"item"} });
     Instruction i1({ InstType::AV, {"n", "5"} });
     Instruction i2({ InstType::TEXT, {"010"} });
     Instruction i3({ InstType::CLOSE, {"item"} });
     ASSERT_EQ(i0, is[0]);
     ASSERT_EQ(i1, is[1]);
     ASSERT_EQ(i2, is[2]);
     ASSERT_EQ(i3, is[3]);
}
