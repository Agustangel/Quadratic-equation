
#define EPSILON 0.00001

#define ONE_ROOT 1
#define TWO_ROOTS 2
#define NO_ROOTS 3
#define INFINITELY_ROOTS 4

#define INCORRECT_INPUT -1

#define EQUAL -2
#define UNEQUAL 0

#define POISON 0


void clear_buffer ();

int input_coefficients(double*, double*, double*);
void output_roots(int, double, double);

int solve_equation(double, double, double, double*, double*);
int solve_linear_equation(double, double, double*, double*);
int solve_quadratic_equation(double, double, double, double*, double*);

int is_equal(double, double);
int is_zero(double);
