/**
 * @file    unit-tests.cpp
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
/*
TEST_CASE( "name", "[object tested]" )
{

    REQUIRE( functiontoTest == TheoricalResult );

}
*/

TEST_CASE("verbose function tests", "[verbose]")
{
    std::string output;
    bool isError;

    output = "";
    isError = verbose(output, false, true);
    /* reading the default value, output = "" and isError = false*/
    REQUIRE( !isError );
    REQUIRE( output == "" );

    output = "gaga";
    /* writing, output2 = "gaga" and isError2 = true */
    isError = verbose(output, true, false);
    REQUIRE( isError );
    REQUIRE( output == "gaga" );


    std::string output2 = "";
    /* reading again, output3 = "gaga" && isError3 = true  */
    isError = verbose(output2);
    REQUIRE( isError );
    REQUIRE( output2 == output );
}
