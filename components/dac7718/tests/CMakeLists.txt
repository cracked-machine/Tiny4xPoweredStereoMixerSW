if($ENV{BUILDTARGET})
else()

    add_executable(dac7718_tests
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/helpers.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_config_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_monitor_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_gpio_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_offset_a_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_offset_b_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_spimode_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_broadcast_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_inputdata0_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_inputdata1_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_inputdata2_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_inputdata3_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_inputdata4_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_inputdata5_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_inputdata6_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/tests/test_inputdata7_register.cpp
        
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/src/value_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/src/config_option_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/src/gpio_option_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/src/monitor_option_register.cpp
        /workspaces/Tiny4xPoweredStereoMixerSW/components/dac7718/src/spimode_option_register.cpp

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