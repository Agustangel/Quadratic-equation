
/*! \mainpage Square equation solver
 * This is a simple program solving square equation */

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#include "quadratic.h"


int main()
{  
    double a = NAN;
    double b = NAN;
    double c = NAN;

    int input_error = 0;

    do
    {
        input_error = input_coefficients(&a, &b, &c);

    } while (input_error == INCORRECT_INPUT);

    assert(!isnanf(a));
    assert(!isnanf(b));
    assert(!isnanf(c));

    double x_1 = NAN;
    double x_2 = NAN;

    int number_roots = 0;

    number_roots = solve_equation(a, b, c, &x_1, &x_2);

    output_roots(number_roots, x_1, x_2);

    return 0;
}
