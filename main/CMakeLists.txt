if($ENV{BUILDTARGET})
    idf_component_register(
        SRCS 
        "main.cpp"
        INCLUDE_DIRS 
        ""
        REQUIRES dac7718
    )
endif()