#include <stdlib.h>
#include "common/utils.h"
#include "template.h"

int main(int argc, char** argv)
{
    parse_opts(argc, argv);

    int *bar = safe_malloc(sizeof(int));
    assert_not_null(bar, __func__, "bar int*");
    true_function();
    free(bar);

    return EXIT_SUCCESS;
}