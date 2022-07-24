
#define EPSILON 0.00001

#define ONE_ROOT 1
#define TWO_ROOTS 2
#define NO_ROOTS 3
#define INFINITELY_ROOTS 4

#define INCORRECT_INPUT -1

#define EQUAL -2
#define UNEQUAL 0

#define POISON 0

#define BLACK "\033[0;30m"
#define BLUE "\033[0;34m"
#define GREEN "\033[0;32m"
#define CYAN "\033[0;36m"
#define RED "\033[0;31m"
#define PURPLE "\033[0;35m"
#define BROWN "\033[0;33m"
#define RESET "\033[0m"


void clear_buffer ();

int input_coefficients(double*, double*, double*);
void output_roots(int, double, double);

int solve_equation(double, double, double, double*, double*);
int solve_linear_equation(double, double, double*, double*);
int solve_quadratic_equation(double, double, double, double*, double*);

int is_equal(double, double);
int is_zero(double);

void set_color(const char*);
void reset_color();
