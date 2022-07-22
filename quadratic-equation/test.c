
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 0.00001

#define EQUAL -2
#define UNEQUAL -3


int solve_linear_equation(double a, double b, double c);
int is_zero(double a);

int is_zero(double a)
{
    printf("a = %lf\n", a);
    fflush (stdout);

    if(fabs(a) < EPSILON)
        return EQUAL;
    else
        return UNEQUAL;

}

int solve_linear_equation(double a, double b, double c)
{
    printf("a = %lf, b = %lf, c = %lf\n", a, b, c);
    if (is_zero(a) == EQUAL)
        return 0;
}

int main()
{
    double a = NAN;
    double b = NAN;
    double c = NAN;

    scanf("%lf %lf %lf", &a, &b, &c);
    printf("a = %lf, b = %lf, c = %lf\n", a, b, c);

    solve_linear_equation(a, b, c);

    return 0;
}
