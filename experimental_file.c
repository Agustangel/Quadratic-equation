
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#define EPSILON 0.00001

#define ONE_ROOT 1
#define TWO_ROOTS 2
#define NO_ROOTS 3
#define INFINITELY_ROOTS 4
#define INCORRECT_INPUT -1
#define EQUAL -2
#define UNEQUAL -3


void clear_buffer ();

int input_coefficients(double*, double*, double*);
void output_roots(int, double, double);

int solve_equation(double, double, double, double*, double*);
int solve_linear_equation(double, double, double*, double*);
int solve_quadratic_equation(double, double, double, double*, double*);

int is_equal(double lhs, double rhs);
int is_zero(double comparison);


void clear_buffer ()
{
    while ( getchar() != '\n' );
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

    else
        return 0;
}


int is_equal(double lhs, double rhs)
{
    assert(!isnanf(lhs));
    assert(!isnanf(rhs));

    if (fabs(lhs - rhs) < EPSILON)
        return EQUAL;
    else
        return UNEQUAL;
}

int is_zero(double comparison)
{
    assert(!isnanf(comparison));

    if(fabs(comparison) < EPSILON)
        return EQUAL;
    else
        return UNEQUAL;
}


int solve_linear_equation(double b, double c, double* x_1, double* x_2)
{
    assert(!isnanf(b));
    assert(!isnanf(c));

    assert(x_1 != NULL);
    assert(x_2 != NULL);

    if(is_zero(b) == EQUAL)
        {
            if(is_zero(c) == EQUAL)
                return INFINITELY_ROOTS;      
            else
                return NO_ROOTS;
        }

        else
        {
            if(is_zero(c) == EQUAL)
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

    if (is_zero(discriminant) == EQUAL)
    {
        *x_1 = *x_2 = -b / (2 * a);
        return ONE_ROOT;
    }

    else if (discriminant > 0)
    {
        double sqrt_discriminant = sqrt(discriminant);

        *x_1 = (-b + sqrt_discriminant) / (2 * a);
        *x_2 = (-b - sqrt_discriminant) / (2 * a);
            
        return TWO_ROOTS;
    }

    else
    {
        return NO_ROOTS;
    }
}

int solve_equation(double a, double b, double c, double* x_1, double* x_2)
{   
    assert(!isnanf(a));
    assert(!isnanf(b));
    assert(!isnanf(c));

    assert(x_1 != NULL);
    assert(x_2 != NULL);

    if (is_zero(a) == EQUAL)
        solve_linear_equation(b, c, x_1, x_2);

    else
        solve_quadratic_equation(a, b, c, x_1, x_2);
}


void output_roots(int number_roots, double x_1, double x_2)
{
    assert(!isnanf(number_roots));
    assert(!isnanf(x_1));
    assert(!isnanf(x_2));

    switch (number_roots)
    {
    case NO_ROOTS:
        printf("No real roots\n");
        break;
    case ONE_ROOT: 
        printf("x_1 = x_2 = %lf\n", x_1);
        break;
    case TWO_ROOTS:
        printf("x_1 = %lf, x_2 = %lf\n", x_1, x_2);
        break;
    case INFINITELY_ROOTS:
        printf("Infinitely roots\n");
        break;
    }
}


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

    printf("%lf %lf", x_1, x_2);
    output_roots(number_roots, x_1, x_2);

    return 0;
}
