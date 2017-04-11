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

TEST(objectstarthandler, test_011)
{
     //
     // [ {
     //   ^
     using namespace json2xml;
     Option O;
     ObjectStartHandler OSH(O, Event::UNDEF);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_array();
     PL++;
     auto is = OSH.handle(TH, PL);
     ASSERT_EQ(0, is.size());
}

TEST(objectstarthandler, test_02)
{
     //
     // { {
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

TEST(objectstarthandler, test_03)
{
     //
     // { ...} {
     //        ^
     using namespace json2xml;
     Option O;
     ObjectStartHandler OSH(O, Event::OBJECTEND);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_object();
     PL++;
     auto is = OSH.handle(TH, PL);
     ASSERT_EQ(1, is.size());
     Instruction i1({ InstType::OPEN, {"json"} });
     ASSERT_EQ(i1, is[0]);
}

TEST(objectstarthandler, test_04)
{
     //
     // [ ...} {
     //        ^
     using namespace json2xml;
     Option O;
     ObjectStartHandler OSH(O, Event::OBJECTEND);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_array();
     PL++;
     PL++;
     auto is = OSH.handle(TH, PL);
     ASSERT_EQ(2, is.size());
     Instruction i1({ InstType::OPEN, {"item"} });
     ASSERT_EQ(i1, is[0]);
     Instruction i2({ InstType::AV, {"n", "2"} });
     ASSERT_EQ(i2, is[1]);
}

TEST(objectstarthandler, test_05)
{
     //
     // [ {
     //   ^
     using namespace json2xml;
     Option O;
     ObjectStartHandler OSH(O, Event::ARRAYSTART);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_array();
     PL++;
     PL++;
     PL++;
     auto is = OSH.handle(TH, PL);
     ASSERT_EQ(2, is.size());
     Instruction i1({ InstType::OPEN, {"item"} });
     ASSERT_EQ(i1, is[0]);
     Instruction i2({ InstType::AV, {"n", "3"} });
     ASSERT_EQ(i2, is[1]);
}

TEST(objectstarthandler, test_06)
{
     //
     // { ...] {
     //        ^
     using namespace json2xml;
     Option O;
     ObjectStartHandler OSH(O, Event::ARRAYEND);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_object();
     PL++;
     PL++;
     PL++;
     auto is = OSH.handle(TH, PL);
     ASSERT_EQ(1, is.size());
     Instruction i1({ InstType::OPEN, {"json"} });
     ASSERT_EQ(i1, is[0]);
}

TEST(objectstarthandler, test_07)
{
     //
     // [ ...] {
     //        ^
     using namespace json2xml;
     Option O;
     ObjectStartHandler OSH(O, Event::ARRAYEND);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_array();
     PL++;
     PL++;
     PL++;
     PL++;
     PL++;
     auto is = OSH.handle(TH, PL);
     ASSERT_EQ(2, is.size());
     Instruction i1({ InstType::OPEN, {"item"} });
     ASSERT_EQ(i1, is[0]);
     Instruction i2({ InstType::AV, {"n", "5"} });
     ASSERT_EQ(i2, is[1]);
}

TEST(objectstarthandler, test_08)
{
     //
     // { key : {
     //         ^
     using namespace json2xml;
     Option O;
     ObjectStartHandler OSH(O, Event::KEY);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_object();
     PL++;
     PL++;
     PL++;
     PL++;
     PL++;
     auto is = OSH.handle(TH, PL);
     ASSERT_EQ(0, is.size());
}

TEST(objectstarthandler, test_10)
{
     //
     // [ key : {
     //         ^
     using namespace json2xml;
     Option O;
     ObjectStartHandler OSH(O, Event::KEY);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_array();
     PL++;
     PL++;
     PL++;
     PL++;
     PL++;
     auto is = OSH.handle(TH, PL);
     ASSERT_EQ(0, is.size());
}

TEST(objectstarthandler, test_11)
{
     //
     // { "value" {
     //           ^
     using namespace json2xml;
     Option O;
     ObjectStartHandler OSH(O, Event::VALUE);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_object();
     PL++;
     PL++;
     PL++;
     PL++;
     PL++;
     auto is = OSH.handle(TH, PL);
     ASSERT_EQ(1, is.size());
     Instruction i1({ InstType::OPEN, {"json"} });
     ASSERT_EQ(i1, is[0]);
}

TEST(objectstarthandler, test_12)
{
     //
     // [ "value" {
     //           ^
     using namespace json2xml;
     Option O;
     ObjectStartHandler OSH(O, Event::VALUE);
     TagHistory TH("json");
     PlaceLooker PL;
     PL.set_array();
     PL++;
     PL++;
     auto is = OSH.handle(TH, PL);
     ASSERT_EQ(2, is.size());
     Instruction i1({ InstType::OPEN, {"item"} });
     ASSERT_EQ(i1, is[0]);
     Instruction i2({ InstType::AV, {"n", "2"} });
     ASSERT_EQ(i2, is[1]);
}
