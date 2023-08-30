#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include "input_checker.h"
#include "utilities.h"
#include "solver.h"
#include "output_analysis.h"

int solver_return = 0;

enum input_result check_quadratic_input(struct quadratic_eq *q_eq)
{
    ASSERT(q_eq != NULL);

    int check = 0;
    while(1)
    {
        check=scanf("%lf %lf %lf", &((*q_eq).a), &((*q_eq).b), &((*q_eq).c));
        if(check == 0)
        {
            if( (getchar()) == 'q' && check_buffer_isspace() == true)
            {
                return EXIT;
            }
            else
            {
                flush_buffer();
                printf("Enter three numbers or 'q' for exit\n");
            }
        }
        else if (check != 3 && check!=0)
        {
            flush_buffer();
            printf("Enter three numbers or 'q' for exit\n");
        }
        else
        {
            if(check_buffer_isspace() == true)
            {
                return ACCEPT;
            }
            else
            {
                flush_buffer();
                printf("Enter three numbers or 'q' for exit\n");
            }
        }
    }
}

enum input_result check_quadratic_input_via_file_(struct quadratic_eq *q_eq, FILE *fp, int *string_number)
{
    if (fp == NULL)
    {
        printf("Not found\n");
        return EXIT;
    }

    int check = 0;
    while(1)
    {
        check = fscanf(fp, "%lf %lf %lf", &((*q_eq).a), &((*q_eq).b), &((*q_eq).c));
        if (check == EOF)
        {
            return EXIT;;
        }

        (*string_number)++;
        if (check != 3)
        {
            printf("Invalid file data: string %d\n", *string_number);
        }
        else
        {
            return ACCEPT;
        }
        flush_buffer_file(fp);
    }
}



