#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "first_char.h"
#include "input_checker.h"
#include "output_analysis.h"
#include "solver.h"
#include "utilities.h"

int main(int argc, const char *argv[])
{
    struct quadratic_eq q_eq = {.a = 0.0, .b = 0.0, .c = 0.0, .x1 = 0.0, .x2 = 0.0};
    int string_number = 0;
    int nFailed_tests = 0;

    bool cmd_string_isEmpty = true;
    if (argc == 3)
    {
        if (MyStrcmp("--test", argv[1]))//проверка ввода
        {
            FILE *fp_tests = fopen(argv[2],"r");//функция
            get_input_from_fileWithTests(fp_tests, count_strings(fp_tests), &nFailed_tests);
            fclose(fp_tests);
            cmd_string_isEmpty = false;
        }
    }
    else if (argc == 2)
    {
        if (MyStrcmp("--help", argv[1]))
        {
            printf("--test filename.exp - runs tests using data from filename.exp\n");
            cmd_string_isEmpty = false;
        }
    }

    int solver_return = 0;
    int input_mode = 'f';
    char file_name[LENGTH] = "";
    FILE * fp = NULL;

    if (cmd_string_isEmpty == true)
    {
        printf("A quadratic equation looks like this: a*x^2 + b*x + c = 0. Enter a,b,c; 'q' - exit.\n");
        printf("Console input - '1', file input - '2'\n");
        if ( (input_mode = check_first_char() ) == '2')
        {
            printf("Enter file name\n");//фунция
            scanf("%s", file_name);
//переполнение буффера
            fp = fopen (file_name, "r");

            while(check_quadratic_input_via_file_(&q_eq, fp, &string_number) == ACCEPT)//проверка файла в отд функцию
            {
                solver_return = solve_quadratic_equation(&q_eq);
                printf("for a = %lf, b = %lf, c = %lf: \n", q_eq.a, q_eq.b, q_eq.c);
                output(&q_eq, solver_return);
            }
            fclose(fp);
            //getchar();
        }
        else if (input_mode == '1')
        {
            printf("Enter a,b,c; 'q' - exit.\n");
            while(check_quadratic_input(&q_eq) == ACCEPT)
            {
                solver_return = solve_quadratic_equation(&q_eq);
                output(&q_eq, solver_return);
                printf("Enter a,b,c; 'q' - exit.\n");
            }
        }
        //getchar();
    }
    return 0;
}



