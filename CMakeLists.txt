cmake_minimum_required(VERSION 3.15)
project(Projet_ThL VERSION 1.0)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

## Compiler flags
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -W")        ## Optimize
    #set(CMAKE_EXE_LINKER_FLAGS "-s")  ## Strip binary
endif()


# SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Compilation Defines
set(EXECUTABLE_OUTPUT_PATH "../")

# Compilation
set(TEST "src/test.cpp")
set(MAIN "src/main.cpp")
set(UNIT_TEST "src/unit-tests.cpp")

#add_library(INTERFACE_LIBS ${LIBS})

add_executable(test ${TEST})
#add_executable(application ${MAIN})
#add_executable(unit_tests ${UNIT_TESTS})

# Linking
target_link_libraries(test ${SDL2_LIBRARIES} pthread)

