#include <ArrayStartHandler.hpp>
#include <gtest/gtest.h>

TEST(arraystarthandler, test_01)
{
     //
     // { ? [
     //     ^
     using namespace json2xml;
     Option O;
     ArrayStartHandler OSH(O, Event::UNDEF);
     TagHistory TH("json");
     PlaceLooker PL;
     PL++;
     PL.set_object();
     auto is = OSH.handle(TH, PL);
     ASSERT_EQ(0, is.size());
}

TEST(arraystarthandler, test_02)
{
     //
     // [ ? [
     //     ^
     using namespace json2xml;
     Option O;
     ArrayStartHandler OSH(O, Event::UNDEF);
     TagHistory TH("json");
     PlaceLooker PL;
     PL++;
     PL.set_array();
     auto is = OSH.handle(TH, PL);
     ASSERT_EQ(0, is.size());
}

TEST(arraystarthandler, test_03)
{
     //
     // ? ? [
     //     ^
     using namespace json2xml;
     Option O;
     ArrayStartHandler OSH(O, Event::UNDEF);
     TagHistory TH("json");
     PlaceLooker PL;
     auto is = OSH.handle(TH, PL);
     ASSERT_EQ(0, is.size());
}

TEST(arraystarthandler, test_04)
{
     //
     // {   [
     //     ^
     using namespace json2xml;
     Option O;
     ArrayStartHandler OSH(O, Event::OBJECTSTART);
     TagHistory TH("json");
     PlaceLooker PL;
     PL++;
     PL.set_object();
     auto is = OSH.handle(TH, PL);
     ASSERT_EQ(1, is.size());
     Instruction i1({ InstType::OPEN, {"json"} });
     ASSERT_EQ(i1, is[0]);
}

TEST(arraystarthandler, test_05)
{
     //
     // {   [
     //     ^
     using namespace json2xml;
     Option O;
     ArrayStartHandler OSH(O, Event::OBJECTSTART);
     TagHistory TH("json");
     PlaceLooker PL;
     PL++;
     PL.set_array();
     auto is = OSH.handle(TH, PL);
     ASSERT_EQ(0, is.size());
}

TEST(arraystarthandler, test_06)
{
     //
     // { ...} [
     //        ^
     using namespace json2xml;
     Option O;
     ArrayStartHandler OSH(O, Event::OBJECTEND);
     TagHistory TH("json");
     PlaceLooker PL;
     PL++;
     PL.set_object();
     auto is = OSH.handle(TH, PL);
     ASSERT_EQ(1, is.size());
     Instruction i1({ InstType::OPEN, {"json"} });
     ASSERT_EQ(i1, is[0]);
}

TEST(arraystarthandler, test_07)
{
     //
     // [ ...} [
     //        ^
     using namespace json2xml;
     Option O;
     ArrayStartHandler OSH(O, Event::OBJECTEND);
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

TEST(arraystarthandler, test_08)
{
     //
     //  ...[ [
     //       ^
     using namespace json2xml;
     Option O;
     ArrayStartHandler OSH(O, Event::ARRAYSTART);
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
