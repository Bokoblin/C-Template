#include <string.h>
#include <unistd.h>
#include "utils.h"

void parse_opts(int argc, char **argv)
{
    int opt;
    while ((opt = getopt(argc, argv, "vh")) != -1) {
        switch (opt) {
            case 'v':
                printf("0.1\n");
                exit(EXIT_SUCCESS);
            case 'h':
                printf("Usage: ./install/server [-g] ./install/*.so\n");
                exit(EXIT_SUCCESS);
            case '?':
                fprintf(stderr, "%s: option '-%c' is invalid: try '-h'\n", argv[0], optopt);
                exit(EXIT_SUCCESS);
            default:
                break;
        }
    }
}

void assert_not_null(const void *ptr, const char *caller_fct, char *description)
{
    if (ptr == NULL) {
        const size_t size = strlen(caller_fct) + strlen(": NULL value on ") + strlen(description) + 1;
        char message[size];
        snprintf(message, size, "%s: NULL value detected.\nDescription: %s\n", caller_fct, description);
        exit_on_error(message);
    }
}

void exit_on_error(char *message)
{
    printf("[ERROR] %s. Now exiting...\n", message);
    exit(EXIT_FAILURE);
}

void *safe_malloc(size_t size)
{
    void *ptr = malloc(size);
    if (ptr == NULL)
        exit_on_error("Memory allocation failure");
    return ptr;
}
