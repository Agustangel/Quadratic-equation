#pragma once

#include <stdio.h>

/*! \file equation.h
 * Equation's properties. */

//! constant for double number comparisons.
static const double epsilon = 0.00001;

//! constant indicating incorrect data entry into the buffer.
static const int INCORRECT_INPUT = -1;

//! constant for incorrect roots.
static const int POISON = 0;

/*! enumeration of possible solution scenarios with values. */
enum numbers_roots
{
    ONE_ROOT         = 1,
    TWO_ROOTS        = 2,
    NO_ROOTS         = 3,
    INFINITELY_ROOTS = 4
};

/*! enumeration colors and their corresponding ANSI values. */
#define BLACK "\033[0;30m"
#define BLUE "\033[0;34m"
#define GREEN "\033[0;32m"
#define CYAN "\033[0;36m"
#define RED "\033[0;31m"
#define PURPLE "\033[0;35m"
#define BROWN "\033[0;33m"
#define RESET "\033[0m"


//! Function clearing input buffer after scanf failure.
void clear_buffer ();

//! Function that receives input from user.
/*! \param a - coefficient with x^2.
    \param b - coefficient with x^1.
    \param c - coefficient with x^0.
 *  \returns result - INCORRECT_INPUT or 0. */
int input_coefficients(double* a, double* b, double* c);

//! Function that prints roots to the screen.
/*! \param number_roots - the number of roots.
    \param x_1 - the first root.
    \param x_2 - the second root. */
void output_roots(int number_roots, double x_1, double x_2);


//! Function that solves the equation
/*! \param a - coefficient with x^2.
    \param b - coefficient with x^1.
    \param c - coefficient with x^0.
    \param &x_1 - pointer to the first root.
    \param &x_2 - pointer to the second root.
 *  \returns result - one of the possible solution scenarios. */
int solve_equation(double a, double b, double c, double* x_1, double* x_2);

//! Function that solves linear equation
/*! \param b - coefficient with x^1.
    \param c - coefficient with x^0.
    \param &x_1 - pointer to the first root.
    \param &x_2 - pointer to the second root.
 *  \returns result - one of the possible solution scenarios. */
int solve_linear_equation(double b, double c, double* x_1, double* x_2);

//! Function that solves the equation
/*! \param a - coefficient with x^2.
    \param b - coefficient with x^1.
    \param c - coefficient with x^0.
    \param &x_1 - pointer to the first root
    \param &x_2 - pointer to the second root
 *  \returns result - one of the possible solution scenarios. */
int solve_quadratic_equation(double a, double b, double c, double* x_1, double* x_2);


//! Function that compares two double numbers
/*! \param lhs - left double number.
/*! \param rhs - right double number.
 *  \returns result - EQUAL or UNEQUAL. */
int is_equal(double lhs, double rhs);

//! Function that compares double number to zero
/*! \param comparison - double number.
 *  \returns result - EQUAL or UNEQUAL. */
int is_zero(double comparison);


//! Sets the color of console output.
/*! \param color - one of the color enumeration. */
void set_color(const char* color);

//! Resets console output color.
void reset_color();
