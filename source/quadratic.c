
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#include "quadratic.h"


void set_color(const char* color)
{
    printf("%s\n", color);
}

void reset_color()
{
    printf(RESET);
}


void clear_buffer ()
{
    int ch = 0;

    while (((ch = getchar()) != '\n') && (ch != EOF));
}

int input_coefficients(double* a, double* b, double* c)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    printf("Input coefficients for quadratic equation:\n");
    int number_coefficients = scanf("%lf %lf %lf", a, b, c);

    if (number_coefficients != 3)
    {
        clear_buffer ();

        printf("Incorrect input coefficients\n");
        return INCORRECT_INPUT;
    }
    return 0;
}


int is_equal(double lhs, double rhs)
{
    assert(!isnanf(lhs));
    assert(!isnanf(rhs));

    return(fabs(lhs - rhs) < epsilon);
}

int is_zero(double comparison)
{
    assert(!isnanf(comparison));

    return(fabs(comparison) < epsilon);
}


int solve_linear_equation(double b, double c, double* x_1, double* x_2)
{
    assert(!isnanf(b));
    assert(!isnanf(c));

    assert(x_1 != NULL);
    assert(x_2 != NULL);

    if(is_zero(b))
    {
        if(is_zero(c))
        {
            *x_1 = POISON;
            *x_2 = POISON;

            return INFINITELY_ROOTS;   
        }  
        else
        {
            *x_1 = POISON;
            *x_2 = POISON;

            return NO_ROOTS;
        }
    }
    else
    {
        if(is_zero(c))
        {
            *x_1 = *x_2 = 0.0;

            return ONE_ROOT;
        }
        else
        {
            *x_1 = *x_2 = -c / b;

            return ONE_ROOT;
        }
    }
}

int solve_quadratic_equation(double a, double b, double c, double* x_1, double* x_2)
{
    assert(!isnanf(a));
    assert(!isnanf(b));
    assert(!isnanf(c));

    assert(x_1 != NULL);
    assert(x_2 != NULL);

    double discriminant = b * b - 4 * a * c;

    if (is_zero(discriminant))
    {
        *x_1 = *x_2 = -b / (2 * a);

        return ONE_ROOT;
    }
    else if (discriminant > 0)
    {
        double sqrt_discriminant = sqrt(discriminant);

        *x_1 = (-b - sqrt_discriminant) / (2 * a);
        *x_2 = (-b + sqrt_discriminant) / (2 * a);

        return TWO_ROOTS;
    }
    else
    {
        *x_1 = POISON;
        *x_2 = POISON;
        
        return NO_ROOTS;
    }
}

int solve_equation(double a, double b, double c, double* x_1, double* x_2)
{   

    if (isnanf(a) || isnanf(b) || isnanf(c))
    {
        *x_1 = POISON;
        *x_2 = POISON;

        return NO_ROOTS;
    }

    assert(!isnanf(a));
    assert(!isnanf(b));
    assert(!isnanf(c));

    assert(x_1 != NULL);
    assert(x_2 != NULL);

    if (isinf(a) || isinf(b) || isinf(c))
    {
        *x_1 = POISON;
        *x_2 = POISON;
        
        return NO_ROOTS;
    }

    if (is_zero(a))
    {
        solve_linear_equation(b, c, x_1, x_2);
    }
    else
    {
        solve_quadratic_equation(a, b, c, x_1, x_2);
    }
}


void output_roots(int number_roots, double x_1, double x_2)
{
    assert(!isnanf(number_roots));
    assert(!isnanf(x_1));
    assert(!isnanf(x_2));

    // TODO default
    switch (number_roots)
    {
    case NO_ROOTS:
        printf("No real roots\n");
        break;

    case ONE_ROOT: 
        printf("x_1 = x_2 = %.3lf\n", x_1);
        break;

    case TWO_ROOTS:
        printf("x_1 = %.3lf, x_2 = %.3lf\n", x_1, x_2);
        break;

    case INFINITELY_ROOTS:
        printf("Infinitely roots\n");
        break;

    default:
        printf("Incorrect case\n");
        break;
    }
}
