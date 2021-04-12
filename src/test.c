#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include "addition.h"
//#include "queue.h"

void setup(void)
{
    printf("Before test\n");
}

void teardown(void)
{
    printf("After test\n");
}

Test(Addition, test_add, .init = setup, .fini = teardown)
{
    cr_assert(add(2, 2) == 4, "Expected add to have a lenght of 4.");
}

Test(Addition, test_add2, .init = setup, .fini = teardown)
{
    cr_assert(add(2, 2) == 5, "Testing purpose");
}
