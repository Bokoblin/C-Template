#include "common_tests_utils.h"
#include "../src/template.h"

int test_true_function()
{
    printf("%s... ", __func__);

    if (!true_function()) {
        return !TEST_SUCCESS;
    }

    return TEST_SUCCESS;
}

int test_false_function()
{
    printf("%s... ", __func__);

    if (false_function()) {
        return !TEST_SUCCESS;
    }

    return TEST_SUCCESS;
}


int main()
{
    printf("----------- TEST TEMPLATE -----------\n");

    int nb_success = 0;
    int nb_tests = 0;

    print_test_result(test_true_function(), &nb_success, &nb_tests);
    print_test_result(test_false_function(), &nb_success, &nb_tests);

    print_test_summary(nb_success, nb_tests);

    return TEST_SUCCESS;
}
