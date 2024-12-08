if($ENV{BUILDTARGET})
else()

    add_executable(dac7718_tests
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/helpers.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_config_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_monitor_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_gpio_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_offset_register.cpp
        
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/src/abstract_value_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/src/offset_value_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/src/config_option_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/src/gpio_option_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/src/monitor_option_register.cpp

    )
    target_include_directories(dac7718_tests PUBLIC
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/inc
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests
    )

    target_link_libraries(dac7718_tests
        GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(dac7718_tests)
    add_test(NAME dac7718 COMMAND dac7718_tests)

endif()