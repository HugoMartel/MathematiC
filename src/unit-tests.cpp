/**
 * @file    test.cpp
 * @brief   Test file to tryout our function
 */

#include <iostream>

#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"

/* including tt's function  */
#include "interface.hpp"

/*------------------------*/
/*        FUNCTIONS       */
/*------------------------*/
void display()
{

}


/*------------------------*/
/*       UNIT TESTS       */
/*------------------------*/
TEST_CASE( "name", "[object tested]" )
{

    REQUIRE( functiontoTest == TheoricalResult );

}

TEST_CASE("verbose", "[rng?]")
{
    std::string output("");
    bool isError1 = false;
    /* reading the default value, output = "" and isError = false*/
    isError = verbose(output, isError, true);
    std::string output2 = "gaga";
    bool isError2 = true;
    /* writing, output2 = "gaga" and isError2 = true */
    isError2 = verbose(output2, isError2);
    std::string output3 = "";
    bool isError3 = false;
    /* reading again, output3 = "gaga" && isError3 = true  */
    isError3 = verbose(output3, isError3, false);
    REQUIRE(!isError1 && isError2 && isError3 && output == std::string("") && output2 == output3);
}
