#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "first_char.h"
#include "input_checker.h"
#include "output_analysis.h"
#include "solver.h"
#include "utilities.h"
#include <string.h>

int main(int argc, char *argv[])
{
    //input_test_quadratic_equation_solver();


    struct quadratic_eq q_eq = {.a = 0.0, .b = 0.0, .c = 0.0, .x1 = 0.0, .x2 = 0.0};

    if(argc == 2 or argc == 3)
    {
        if (MyStrcmp("--test", argv[1]))
        {
            if(argc == 2)
            {
                printf("Enter file_name.exp\n");
            }
            else
            {
                FILE *fp_tests = fopen(argv[2],"r");
                get_input_from_fileWithTests(fp_tests, count_strings(fp_tests));
                fclose(fp_tests);
            }
        }
        else
        {
            printf("Enter --test to run tests via file\n");
        }
    }

    /*FILE *fp_tests = fopen("tests.txt","r");
    get_input_from_fileWithTests(fp_tests, count_strings(fp_tests));
    fclose(fp_tests);*/

    //run_test();

    /*double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    double x1 = 0.0;
    double x2 = 0.0;*/

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

    int indicator1 = 'f';
    char file_name[40] = "";
    FILE * fp;

    printf("A quadratic equation looks like this: a*x^2 + b*x + c = 0. Enter a,b,c; 'q' - exit.\n");
    printf("Console input - '1', file input - '2'\n");
    if ( (indicator1 = check_first_char() ) == '2')
    {
        printf("Enter file name\n");
        scanf("%s", file_name);

        fp = fopen (file_name, "r");

        while(check_quadratic_input_via_file_(&q_eq, fp) == ACCEPT)
        {
            solver_return = solve_quadratic_equation(&q_eq);
            printf("for a = %lf, b = %lf, c = %lf: \n", q_eq.a, q_eq.b, q_eq.c);
            output_f(&q_eq, solver_return);
        }
        fclose(fp);
        //getchar();
    }
    else if (indicator1 == '1')
    {
        printf("Enter a,b,c; 'q' - exit.\n");
        while(check_quadratic_input(&q_eq) == ACCEPT)
        {
            solver_return = solve_quadratic_equation(&q_eq);
            output_f(&q_eq, solver_return);
            printf("Enter a,b,c; 'q' - exit.\n");
        }
    }
    //getchar();

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

    return 0;
}



