#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <memory>

#include "formatting.hpp"

SCENARIO("this is a simple test to verify catch", "[formatting]") {

    GIVEN("a Formatting instance was created and a float is given") {
        auto f = std::make_unique<Formatting>();
        auto val = 1.678;

        REQUIRE(f);

        WHEN("want to format a float with no decimal digits") {

            std::string format = "{:.0f}";
            auto result = f->format(format, val);

            THEN("the resoult should be rounded as expected") {
                REQUIRE( result == "2");
            }
        }

        WHEN("want to format a float with two decimal digits") {

            std::string format = "{:.2f}";
            auto result = f->format(format, val);

            THEN("should get the right number of decimals") {
                REQUIRE( result == "1.68" );
            }
        }
    }
}
