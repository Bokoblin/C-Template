if(ENABLE_TESTS)

#--------------------------------------------------------
#       SET TEST EXECUTABLES
#--------------------------------------------------------

set(TEST_TEMPLATE test_template)

#--------------------------------------------------------
#       SET TEST SOURCES
#--------------------------------------------------------
file(GLOB TEST_SOURCE_FILES
        "common_tests_utils.c"
        "test_template.c"
        "test_template.c"
        "../src/template.c"
        )

#--------------------------------------------------------
#       CONFIGURE BUILDING
#--------------------------------------------------------

add_executable(${TEST_TEMPLATE} ${TEST_SOURCE_FILES})

#--------------------------------------------------------
#       CONFIGURE TESTS
#--------------------------------------------------------

add_test(NAME ${TEST_TEMPLATE} COMMAND make ${TEST_TEMPLATE})

enable_testing()

endif()