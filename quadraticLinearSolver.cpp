#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "first_char.h"
#include "input_checker.h"
#include "output_analysis.h"
#include "solver.h"
#include "utilities.h"


int main(void)
{
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    char indicator1 = 'f';

    double x1 = 0.0;
    double x2 = 0.0;

    int solver_return = 0;

    printf("Please, enter '1' to solve a quadratic equation, '2' - a linear equation, 'q' - exit.\n");

    if ((indicator1 = check_first_char()) == '1')
    {
        printf("A quadratic equation looks like this: a*x^2 + b*x + c = 0. Enter a,b,c; 'q' - exit.\n");
        while(check_quadratic_input(&a, &b, &c) == ACCEPT)
        {
            solver_return = quadratic_equation_solver(a, b, c, &x1, &x2);
            output_f(&x1, &x2, solver_return);
            printf("Enter a,b,c; 'q' - exit.\n");
        }
    }
    else if (indicator1 == '2')
    {
        printf("A linear equation looks like this: b*x + c = 0. Enter b,c; 'q' - exit.\n");
        while(check_linear_input(&b, &c) == ACCEPT)
        {
            solver_return = linear_equation_solver(b, c, &x1);
            output_f(&x1, &x2, solver_return);
            printf("Enter b,c; 'q' - exit.\n");
        }
    }

    /*getchar(); //for *.exe
    getchar();
    getchar();*/

    return 0;
}



