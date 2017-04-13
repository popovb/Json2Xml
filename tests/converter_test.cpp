#include <Json2Xml/Converter.hpp>
#include <Json2Xml/Option.hpp>
#include <Json2Xml/NullHandler.hpp>
#include <Json2Xml/TestHandler.hpp>
#include <fstream>
#include <gtest/gtest.h>

TEST(converter, test_01)
{
     using namespace json2xml;
     std::ifstream in("first_test_05.json");
     Converter C;
     ASSERT_TRUE(true);
}

TEST(converter, test_02)
{
     using namespace json2xml;
     std::ifstream in("first_test_05.json");
     Option O;
     Converter C(O);
     ASSERT_TRUE(true);
}

TEST(converter, test_03)
{
     using namespace json2xml;
     std::ifstream in("first_test_05.json");
     Converter C;
     NullHandler NH;
     ASSERT_TRUE(C.convert(in, NH));
}

TEST(converter, test_04)
{
     using namespace json2xml;
     std::ifstream in("first_test_05.json");
     Converter C;
     TestHandler TH("\n");
     ASSERT_TRUE(C.convert(in, TH));
     std::string ETALON = R"-(O[Json]
O[hello5]
T[world5]
C[hello5]
O[t]
T[TRUE]
C[t]
O[f]
T[FALSE]
C[f]
O[n]
T[NULL]
C[n]
O[i]
T[123]
C[i]
O[pi]
O[x]
T[6]
C[x]
C[pi]
O[pi2]
O[item]
A[n][1]
T[x]
C[item]
O[item]
A[n][2]
T[6]
C[item]
C[pi2]
C[Json]
)-";
     ASSERT_EQ(ETALON, TH.get());
}
