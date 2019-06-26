#include "catch.hpp"

#include <string>
#include <regex>
#include <algorithm>

using namespace std;

SCENARIO("this is a test to learn how to use c++ regex", "[regex]") {

    GIVEN("given a firmware filename") {

        string str = "ETRK_[TEX]_[DEF]_[568]_[MA_11_22_33_44].bin";

        WHEN("i want to extract version") {
            //regex e { R"(([[:alnum:]]+)_.*_\[(\w+)\].bin$)" };
            regex reg { R"(^([[:alnum:]]+)_\[([[:alnum:]]+)\]_\[([[:alnum:]]+)\]_\[([[:alnum:]]+)\]_\[([[:alnum:]]+)_(\d+_\d+_\d+_\d+)\]\.bin$)" };
            smatch match;

            if (regex_match(str, match, reg)) {
                REQUIRE(match.size() == 7);
                REQUIRE(match[0] == "ETRK_[TEX]_[DEF]_[568]_[MA_11_22_33_44].bin");
                REQUIRE(match[1] == "ETRK");
                REQUIRE(match[2] == "TEX");
                REQUIRE(match[3] == "DEF");
                REQUIRE(match[4] == "568");
                REQUIRE(match[5] == "MA");
                REQUIRE(match[6] == "11_22_33_44");

                istringstream iss;
                int val;

                string s = match[6];
                std::replace(s.begin(), s.end(), '_', ' ');

                iss.str(s);
                iss >> val;
                REQUIRE(val == 11);

                iss >> val;
                REQUIRE(val == 22);

                iss >> val;
                REQUIRE(val == 33);

                iss >> val;
                REQUIRE(val == 44);
            }

            
        }
    }
}