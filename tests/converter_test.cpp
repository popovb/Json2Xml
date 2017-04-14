#include <Json2Xml/Converter.hpp>
#include <Json2Xml/Option.hpp>
#include <Json2Xml/NullHandler.hpp>
#include <Json2Xml/TestHandler.hpp>
#include <Json2Xml/PrettyXMLHandler.hpp>
#include <fstream>
#include <sstream>
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

TEST(converter, test_05)
{
     using namespace json2xml;
     std::ifstream in("first_test_06.json");
     Option O("root");
     Converter C(O);
     TestHandler TH("\n");
     ASSERT_TRUE(C.convert(in, TH));
     std::string ETALON = R"-(O[root]
O[pi2]
O[item]
A[n][1]
T[x]
C[item]
O[item]
A[n][2]
T[6]
C[item]
O[item]
A[n][3]
T[y]
C[item]
O[item]
A[n][4]
T[7]
C[item]
C[pi2]
O[pi3]
O[pi4]
O[item]
A[n][1]
T[1]
C[item]
O[item]
A[n][2]
T[2]
C[item]
O[item]
A[n][3]
T[3]
C[item]
C[pi4]
O[x]
O[x1]
T[y1]
C[x1]
C[x]
C[pi3]
C[root]
)-";
     ASSERT_EQ(ETALON, TH.get());
}

TEST(converter, test_06)
{
     using namespace json2xml;
     std::ifstream in("first_test_07.json");
     Option O("root", "default");
     Converter C(O);
     TestHandler TH("\n");
     ASSERT_TRUE(C.convert(in, TH));
     std::string ETALON = R"-(O[root]
O[x]
O[item]
A[n][1]
T[1]
C[item]
O[item]
A[n][2]
T[2]
C[item]
O[item]
A[n][3]
T[3]
C[item]
O[item]
A[n][4]
O[item]
A[n][1]
T[4]
C[item]
O[item]
A[n][2]
T[5]
C[item]
O[item]
A[n][3]
T[6]
C[item]
O[item]
A[n][4]
O[item]
A[n][1]
T[7]
C[item]
O[item]
A[n][2]
T[8]
C[item]
O[item]
A[n][3]
T[9]
C[item]
C[item]
C[item]
C[x]
O[y]
O[a]
O[b]
O[c]
T[d]
C[c]
C[b]
C[a]
C[y]
C[root]
)-";
     ASSERT_EQ(ETALON, TH.get());
}

TEST(converter, test_07)
{
     using namespace json2xml;
     std::ifstream in("first_test_07.json");
     Option O("root", "default");
     Converter C(O);

     std::stringstream ss;
     PrettyXMLHandler TH(ss, "\n", 2);

     ASSERT_TRUE(C.convert(in, TH));
     std::string ETALON = R"-(<root>
  <x>
    <item n="1">
      1
    </item>
    <item n="2">
      2
    </item>
    <item n="3">
      3
    </item>
    <item n="4">
      <item n="1">
        4
      </item>
      <item n="2">
        5
      </item>
      <item n="3">
        6
      </item>
      <item n="4">
        <item n="1">
          7
        </item>
        <item n="2">
          8
        </item>
        <item n="3">
          9
        </item>
      </item>
    </item>
  </x>
  <y>
    <a>
      <b>
        <c>
          d
        </c>
      </b>
    </a>
  </y>
</root>
)-";
     ASSERT_EQ(ETALON, ss.str());
}
