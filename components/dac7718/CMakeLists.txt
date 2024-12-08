if($ENV{BUILDTARGET})

    idf_component_register(
        SRCS 
        "src/config_option_register.cpp"
        "src/gpio_option_register.cpp"
        "src/monitor_option_register.cpp"
        "src/abstract_value_register.cpp"
        "src/offset_value_register.cpp"
        INCLUDE_DIRS 
        "inc"
    )

endif()