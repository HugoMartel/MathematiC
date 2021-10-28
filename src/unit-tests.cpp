/**
 * @file    test.cpp
 * @brief   Test file to tryout our function
 */

#include <iostream>

#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"


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

