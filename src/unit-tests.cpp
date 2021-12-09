/**
 * @file    unit-tests.cpp
 * @brief   Test file to tryout our function
 */

#include <iostream>

#ifndef __DEBUG__
#define __DEBUG__
#endif

#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"

#include "interface.hpp"
#include "mathGraph.hpp"

#include "parser.yy.hpp"


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
    /* writing, output2 = "gaga" and isError = false */
    isError = verbose(output, false, false);
    REQUIRE( !isError );/* Error didn't change */
    REQUIRE( output == "gaga" );


    std::string output2 = "";
    /* reading again, output2 = "gaga" && isError = true  */
    isError = verbose(output2, true, true);
    REQUIRE( !isError );/* bool doesn't change since we are reading */
    REQUIRE( output2 == output );

    output = "zeze";
    /* Reset case */
    verbose(output, false, false, true);
    /* Update the resetted string */
    verbose(output, false, true);/* Read */
    REQUIRE( output == "" );

}


TEST_CASE("expr PLUS expr", "[plus]")
{
    /* Code */
    std::ofstream file("build/test.matc");

    /*Writing the file*/
    file << "def f: (x) => { return x + 2; } draw f;";
    /* Close the file*/
    file.close();

    /* Compile Code */
    GraphSetup testGraph;
    compileCode("build/test.matc", &testGraph);

    /* Check function result */
    REQUIRE( testGraph.curvesFunctions["f"](2.) == 4. );
    REQUIRE( testGraph.curvesFunctions["f"](-2.) == 0. );
    REQUIRE( testGraph.curvesFunctions["f"](-4.) == -2. );
    REQUIRE( testGraph.curvesFunctions["f"](0.) == 2. );

}

TEST_CASE("expr MIN expr", "[moins]")
{
    /* Code */
    std::ofstream file("build/test.matc");

    /*Writing the file*/
    file << "def f: (x) => { return x - 2; } draw f;";
    /* Close the file*/
    file.close();

    /* Compile Code */
    GraphSetup testGraph;
    compileCode("build/test.matc", &testGraph);

    /* Check function result */
    REQUIRE( testGraph.curvesFunctions["f"](2.) == 0. );
    REQUIRE( testGraph.curvesFunctions["f"](-2.) == -4. );
    REQUIRE( testGraph.curvesFunctions["f"](4.) == 2. );
    REQUIRE( testGraph.curvesFunctions["f"](0.) == -2. );

}

TEST_CASE("MIN expr", "[negatif]")
{
    /* Code */
    std::ofstream file("build/test.matc");

    /*Writing the file*/
    file << "def f: (x) => { return - x ; } draw f;";
    /* Close the file*/
    file.close();

    /* Compile Code */
    GraphSetup testGraph;
    compileCode("build/test.matc", &testGraph);

    /* Check function result */
    REQUIRE( testGraph.curvesFunctions["f"](2.) == -2. );
    REQUIRE( testGraph.curvesFunctions["f"](-2.) == 2. );
    REQUIRE( testGraph.curvesFunctions["f"](0.) == 0. );

}

TEST_CASE("expr TIMES expr", "[fois]")
{
    /* Code */
    std::ofstream file("build/test.matc");

    /*Writing the file*/
    file << "def f: (x) => { return x * 2; } draw f;";
    /* Close the file*/
    file.close();

    /* Compile Code */
    GraphSetup testGraph;
    compileCode("build/test.matc", &testGraph);

    /* Check function result */
    REQUIRE( testGraph.curvesFunctions["f"](2.) == 4. );
    REQUIRE( testGraph.curvesFunctions["f"](-2.) == -4. );
    REQUIRE( testGraph.curvesFunctions["f"](0.) == 0. );

}

TEST_CASE("expr DIV expr", "[DIV]")
{
    /* Code */
    std::ofstream file("build/test.matc");

    /*Writing the file*/
    file << "def f: (x) => { return 2 / x; } draw f;";
    /* Close the file*/
    file.close();

    /* Compile Code */
    GraphSetup testGraph;
    compileCode("build/test.matc", &testGraph);

    /* Check function result */
    REQUIRE( testGraph.curvesFunctions["f"](2.) == 1. );
    REQUIRE( testGraph.curvesFunctions["f"](-2.) == -1. );
    REQUIRE( testGraph.curvesFunctions["f"](0.) == DBL_MAX );//! should return error

}

TEST_CASE("expr ^ expr", "[POW]")
{
    /* Code */
    std::ofstream file("build/test.matc");

    /*Writing the file*/
    file << "def f: (x) => { return x ^ 2; } draw f;";
    /* Close the file*/
    file.close();

    /* Compile Code */
    GraphSetup testGraph;
    compileCode("build/test.matc", &testGraph);

    /* Check function result */
    REQUIRE( testGraph.curvesFunctions["f"](2.) == 4. );
    REQUIRE( testGraph.curvesFunctions["f"](-2.) == 4. );
    REQUIRE( testGraph.curvesFunctions["f"](0.) == 0. );

}

TEST_CASE("POW '(' expr ',' expr ')'", "[pow]")
{
    /* Code */
    std::ofstream file("build/test.matc");

    /*Writing the file*/
    file << "def f: (x) => { return pow( x , 2 ); } draw f;";
    /* Close the file*/
    file.close();

    /* Compile Code */
    GraphSetup testGraph;
    compileCode("build/test.matc", &testGraph);

    /* Check function result */
    REQUIRE( testGraph.curvesFunctions["f"](2.) == 4. );
    REQUIRE( testGraph.curvesFunctions["f"](-2.) == 4. );
    REQUIRE( testGraph.curvesFunctions["f"](0.) == 0. );

}

TEST_CASE("EXP '(' expr ')'", "[exp]")
{
    /* Code */
    std::ofstream file("build/test.matc");

    /*Writing the file*/
    file << "def f: (x) => { return exp(x); } draw f;";
    /* Close the file*/
    file.close();

    /* Compile Code */
    GraphSetup testGraph;
    compileCode("build/test.matc", &testGraph);

    /* Check function result */
    REQUIRE( testGraph.curvesFunctions["f"](0.) == 1. );

}

TEST_CASE("LOG '(' expr ')'", "[log]")
{
    /* Code */
    std::ofstream file("build/test.matc");

    /*Writing the file*/
    file << "def f: (x) => { return log(x); } draw f;";
    /* Close the file*/
    file.close();

    /* Compile Code */
    GraphSetup testGraph;
    compileCode("build/test.matc", &testGraph);

    /* Check function result */
    REQUIRE( testGraph.curvesFunctions["f"](1.) == 0. );
}

TEST_CASE("SQRT '(' expr ')'", "[sqrt]")
{
    /* Code */
    std::ofstream file("build/test.matc");

    /*Writing the file*/
    file << "def f: (x) => { return sqrt(x); } draw f;";
    /* Close the file*/
    file.close();

    /* Compile Code */
    GraphSetup testGraph;
    compileCode("build/test.matc", &testGraph);

    /* Check function result */
    REQUIRE( testGraph.curvesFunctions["f"](4.) == 2. );
    REQUIRE( testGraph.curvesFunctions["f"](-2.) == -1 );//! should return error

}

TEST_CASE("IF logic '{' instruction '}' ELSE '{' instruction '}'", "[if]")
{
    /* Code */
    std::ofstream file("build/test.matc");

    /*Writing the file*/
    file << "def f: (x) => { if x == 4 { x += 1; } else { x -= 1; } return x; } draw f;";
    /* Close the file*/
    file.close();

    /* Compile Code */
    GraphSetup testGraph;
    compileCode("build/test.matc", &testGraph);

    /* Check function result */
    REQUIRE( testGraph.curvesFunctions["f"](4.) == 5. );
    REQUIRE( testGraph.curvesFunctions["f"](3.) == 2. );

}

TEST_CASE("FOR VAR in '[' expr ':' expr ':' expr ']' '{' instruction '}'", "[for]")
{
    /* Code */
    std::ofstream file("build/test.matc");

    /*Writing the file*/
    file << "def f: (x) => { for i in [5:2:11] { x += i; } return x; } draw f;";
    /* Close the file*/
    file.close();

    /* Compile Code */
    GraphSetup testGraph;
    compileCode("build/test.matc", &testGraph);

    /* Check function result */
    REQUIRE( testGraph.curvesFunctions["f"](2.) == 34. );

}


TEST_CASE("WHILE logic '{' instruction '}'", "[while]")
{
    /* Code */
    std::ofstream file("build/test.matc");

    /*Writing the file*/
    file << "def f: (x) => { while x <= 3 { x += 1; } return x; } draw f;";
    /* Close the file*/
    file.close();

    /* Compile Code */
    GraphSetup testGraph;
    compileCode("build/test.matc", &testGraph);

    /* Check function result */
    REQUIRE( testGraph.curvesFunctions["f"](2.) == 4. );
    REQUIRE( testGraph.curvesFunctions["f"](4.) == 4. );// I have no idea if it's go in while one time

}
