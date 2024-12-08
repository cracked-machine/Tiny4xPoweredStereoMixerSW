
cmake_minimum_required(VERSION 3.16)

set(COMMON_COMPILER_OPTIONS -Wall -Wextra -Werror -Wswitch-enum)
set(DEBUG_COMPILER_OPTIONS -g -O0 -ftest-coverage)
set(RELEASE_COMPILER_OPTIONS -O3)

set(COV_COMPILER_OPTIONS -ftest-coverage)
set(COV_LINKER_OPTIONS -lgcov --coverage)


if($ENV{BUILDTARGET})
    include($ENV{IDF_PATH}/tools/cmake/project.cmake)
    project(TinyMixer)
    # gives a warning about an omitted enumeration code even if there is a default label. 
    idf_build_set_property(COMPILE_OPTIONS ${COMMON_COMPILER_OPTIONS} ${RELEASE_COMPILER_OPTIONS} APPEND)
else()
    
    project(TinyMixer VERSION 1.0 LANGUAGES CXX)
    add_compile_options(${COMMON_COMPILER_OPTIONS} ${DEBUG_COMPILER_OPTIONS})

    # set(CMAKE_CXX_STANDARD 14)
    # set(CMAKE_CXX_STANDARD_REQUIRED ON)

    include(FetchContent)
    FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    FetchContent_MakeAvailable(googletest)
    
    include(CTest)
    
    add_subdirectory(components/dac7718/tests)
    

endif()



