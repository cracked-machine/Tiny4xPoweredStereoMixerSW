
cmake_minimum_required(VERSION 3.16)

if($ENV{BUILDTARGET})
    include($ENV{IDF_PATH}/tools/cmake/project.cmake)
    project(TinyMixer)
else()
    project(
        TinyMixer
        VERSION 1.0
        LANGUAGES CXX
    )

    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    include(FetchContent)
    FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    FetchContent_MakeAvailable(googletest)
    
    add_subdirectory(components/dac7718)

endif()



