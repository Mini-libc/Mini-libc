#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include "addition.h"

void setup2(void)
{
    printf("Before test2\n");
}

void teardown2(void)
{
    printf("After test2\n");
}

Test(Addition, test2_add, .init = setup2, .fini = teardown2)
{
    cr_assert(add(3, 3) == 6, "Expected add to have a lenght of 6.");
}

Test(Addition, test2_add2, .init = setup2, .fini = teardown2)
{
    cr_assert(add(2, 2) == 5, "Testing purpose for test2");
}
