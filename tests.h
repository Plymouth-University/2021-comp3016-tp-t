/**
* DO NOT MODIFY! 
* Test File for the FileReader
* A final version will be relased close to the deadline with mroe detailed tests.
*/
#pragma once 
#include <string>
#include "../FileReader.h" 
//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"


TEST_CASE( "STD 1: Creating a FileReader object"  ) {
    FileReader reader = FileReader();
    
    CHECK(reader.getCount() == 0);
}

TEST_CASE("STD 2: Modifying Additional Values" ) {
    FileReader reader = FileReader();
    reader.resetCounter();
    reader.increase(0);

    REQUIRE(reader.getCount() == 0);
    reader.increase(1);
    reader.increase(1);

    CHECK(reader.getCount() == 3  );
    reader.resetCounter();
    CHECK(reader.getCount() == 0);
}

TEST_CASE("ADV 1: Opening and Reading a simple PLY File") {
    FileReader reader = FileReader();

    REQUIRE(reader.getLastText().empty());
    CHECK(reader.addText("some"));
    REQUIRE(reader.getLastText().compare("some")); // https://www.cplusplus.com/reference/string/string/compare/
    CHECK(reader.addText("text"));
    REQUIRE(reader.addText("text") == false);

}