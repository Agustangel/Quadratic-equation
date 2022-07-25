#pragma once


//! \struct quadratic_test "unit_tests.h"
/*! Structure of the equation, which include equation'c coefficients and roots. */
struct quadratic_test
{

    double a; /*!< Coefficient with x^2. */
    double b; /*!< Coefficient with x^1. */
    double c; /*!< Coefficient with x^0. */

    double x_1_expected; /*!< First expected root. */
    double x_2_expected; /*!< Second expected root. */

};

//! Function that runs unit tests
/*! \param &test - pointer to the test which need to run.
    \param &test_number - pointer to test number.*/
void quadratic_test_run(struct quadratic_test*, int*);
