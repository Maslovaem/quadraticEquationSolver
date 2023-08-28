#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "first_char.h"
#include "input_checker.h"
#include "output_analysis.h"
#include "solver.h"
#include "utilities.h"
#include <string.h>

int main(void)
{
    //input_test_quadratic_equation_solver();

    FILE *fp_tests = fopen("tests.txt","r");
    check_input_from_fileWithTests(fp_tests, count_strings(fp_tests));
    fclose(fp_tests);

    //run_test();

    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    double x1 = 0.0;
    double x2 = 0.0;

    int solver_return = 0;

    /*printf("Enter '1' to solve a quadratic equation, '2' - a linear equation, 'q' - exit.\n");

    if ((indicator1 = check_first_char()) == '1')
    {
        printf("A quadratic equation looks like this: a*x^2 + b*x + c = 0. Enter a,b,c; 'q' - exit.\n");
        while(check_quadratic_input(&a, &b, &c) == ACCEPT)
        {
            solver_return = solve_quadratic_equation(a, b, c, &x1, &x2);
            output_f(&x1, &x2, solver_return);
            printf("Enter a,b,c; 'q' - exit.\n");
        }
    }
    else if (indicator1 == '2')
    {
        printf("A linear equation looks like this: b*x + c = 0. Enter b,c; 'q' - exit.\n");
        while(check_linear_input(&b, &c) == ACCEPT)
        {
            solver_return = solve_linear_equation(b, c, &x1);
            output_f(&x1, &x2, solver_return);
            printf("Enter b,c; 'q' - exit.\n");
        }
    }*/

    char indicator1 = 'f';
    char file_name[40] = "";
    FILE * fp;

    printf("A quadratic equation looks like this: a*x^2 + b*x + c = 0. Enter a,b,c; 'q' - exit.\n");
    printf("Console input - '1', file input - '2'\n");
    if ( (indicator1 = check_first_char()) == '2')
    {
        printf("Enter file name\n");
        scanf("%s", file_name);

        fp = fopen (file_name, "r");

        show_calc_results_using_file_and_struct(fp);
        fclose(fp);
    }
    else if ( indicator1 == '1')
    {
        printf("Enter a,b,c; 'q' - exit.\n");
        while(check_quadratic_input(&a, &b, &c) == ACCEPT)
        {
            solver_return = solve_quadratic_equation(a, b, c, &x1, &x2);
            output_f(x1, x2, solver_return);
            printf("Enter a,b,c; 'q' - exit.\n");
        }
    }

    //printf("Enter '1' to solve a quadratic equation, '2' - a linear equation, 'q' - exit.\n");

    /*if ((indicator1 = check_first_char()) == '1')
    {*/


    //without struct
    /*printf("A quadratic equation looks like this: a*x^2 + b*x + c = 0. Enter a,b,c; 'q' - exit.\n");
    printf("Enter file name\n");
    scanf("%s", file_name);
    fp = fopen (file_name, "r");
    while(check_quadratic_input_via_file(&a, &b, &c, fp) == ACCEPT)//&eq
    {
        solver_return = solve_quadratic_equation(a, b, c, &x1, &x2);
        output_f(&x1, &x2, solver_return);
    }*/


    /*}
    else if (indicator1 == '2')
    {
        printf("A linear equation looks like this: b*x + c = 0. Enter b,c; 'q' - exit.\n");
        while(check_linear_input(&b, &c) == ACCEPT)
        {
            solver_return = solve_linear_equation(b, c, &x1);
            output_f(&x1, &x2, solver_return);
        }
    }*/

    /*getchar(); //for *.exe
    getchar();
    getchar();*/

    return 0;
}



