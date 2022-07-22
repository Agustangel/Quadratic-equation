
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "unit_tests.h"
#include "quadratic.h"


struct quadratic_test tests[] = {{1, 2, 1, -1, -1}, 
                                 {0, 3, -12, 4, 4}, 
                                 {2, 3, -9, -3, 1.5}, 
                                 {4, 1, 5, 0, 0}, 
                                 {0, 0, 0, 0, 0}, 
                                 {0, 0, 5, 0, 0}, 
                                 {5, 'b', 3, POISON, POISON}, 
                                 {1, 5, 6, -3, -2}, 
                                 {'a', 'a', 'a', POISON, POISON}, 
                                 {INFINITY, INFINITY, INFINITY, POISON, POISON},
                                 {5, INFINITY, INFINITY, POISON, POISON},
                                 {INFINITY, 123, INFINITY, POISON, POISON}};


void quadratic_test_run(struct quadratic_test* test, int* test_number)
{

    double x_1 = NAN;
    double x_2 = NAN;

    solve_equation(test->a, test->b, test->c, &x_1, &x_2);

    if (is_equal(x_1, test->x_1_expected) && is_equal(x_2, test->x_2_expected))
    {
        printf("TEST %d: a = %lf, b = %lf, c = %lf SUCCESS, expected: x_1 = %lf, x_2 = %lf, got: x_1 = %lf, x_2 = %lf\n", *test_number, test->a, test->b, test->c, test->x_1_expected, test->x_2_expected, x_1, x_2);
    }

    else
    {
        printf("TEST %d: a = %lf, b = %lf, c = %lf,FAIL expected: x_1 = %lf, x_2 = %lf, got: x_1 = %lf, x_2 = %lf\n", *test_number, test->a, test->b, test->c, \
                                                                                                                       test->x_1_expected, test->x_2_expected, x_1, x_2);
    }

}

int main()
{
    int test_number = 1;

    for (int idx = 0; idx < sizeof(tests) / sizeof(struct quadratic_test); idx++)
    {
        quadratic_test_run(&tests[idx], &test_number);
        ++test_number;
    }

    return 0;
}
