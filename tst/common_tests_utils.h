#ifndef COMMON_TESTS_UTILS_H
#define COMMON_TESTS_UTILS_H

#ifndef SUCCESS
#define SUCCESS 0
#endif

#define TEST_SUCCESS 0

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////
///     COMMON TESTS FUNCTIONS
////////////////////////////////////////////////////////////////////

/**
 * @brief Print if a test succeeded or not, in color
 * @param result the test result
 * @param nb_success the number of test successes
 * @param nb_tests the number of test executed
 */
void print_test_result(int result, int *nb_success, int *nb_tests);

/**
 * @brief Print tests results
 * @param nb_success number of successes
 * @param nb_tests number of tests
 */
void print_test_summary(int nb_success, int nb_tests);

#endif