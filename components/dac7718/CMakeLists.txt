if($ENV{BUILDTARGET})

    idf_component_register(
        SRCS 
        "src/value_register.cpp"
        "src/config_option_register.cpp"
        "src/gpio_option_register.cpp"
        "src/monitor_option_register.cpp"
        INCLUDE_DIRS 
        "inc"
    )

endif()