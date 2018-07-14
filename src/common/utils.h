#ifndef UTILS_H
#define UTILS_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Function for parsing the options of the program. <br>
 * Available options are :          <br>
 * -v       : displays app version  <br>
 * -h       : displays the help
 * @param argc the number of argument
 * @param argv  the list of arguments
 */
void parse_opts(int argc, char **argv);


/**
 * @brief Check that a pointer isn't null, quit otherwise
 * @param ptr the pointer to check
 * @param caller_fct the function calling the assert check
 * @param description a description of the pointer
 */
void assert_not_null(const void *ptr, const char *caller_fct, char *description);


/**
 * @brief Print a custom error message and exit the application
 * @param message the message to print
 */
void exit_on_error(char* message);


/**
 * @brief Perform a malloc and interrupt program on memory allocation failure
 * @param size the size to allocate
 * @return a generic pointer
 */
void* safe_malloc(size_t size);

#endif
