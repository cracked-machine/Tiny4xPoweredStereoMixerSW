if($ENV{BUILDTARGET})
else()

    add_executable(dac7718_tests
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_dac7718.cpp
        
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/src/dac7718.cpp
    )
    target_include_directories(dac7718_tests PUBLIC
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/inc
    )

    target_link_libraries(dac7718_tests
        GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(dac7718_tests)
    add_test(NAME dac7718 COMMAND dac7718_tests)

endif()