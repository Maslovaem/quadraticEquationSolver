#include "input_checker.h"
#include <stdio.h>
#include "utilities.h"
#include "solver.h"
#include "output_analysis.h"
#include <ctype.h>
#include <cassert>
#include <string.h>

int solver_return = 0;

enum input_result check_quadratic_input(struct quadratic_eq *q_eq)
{

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


/*enum input_result check_linear_input(double * b_p, double * c_p)
{
    ASSERT(b_p!=NULL);
    ASSERT(c_p!=NULL);

    int check = 0;
    while((check=scanf("%lf %lf", b_p, c_p)) != 2)
    {
        if(getchar()=='q'&& check==0 && getchar()=='\n')
        {
            return EXIT;
        }
        else
        {
            printf("Enter two numbers\n");
            flush_buffer();
        }
    }
    flush_buffer();
    return ACCEPT;
}*/

/*enum input_result check_quadratic_input_via_file(double * a_p,double * b_p,double * c_p, FILE * fp)//without struct
{
    ASSERT(a_p!=NULL);
    ASSERT(b_p!=NULL);
    ASSERT(c_p!=NULL);

    if (fp == NULL)
    {
        printf("Not found\n");
        return EXIT;
    }
    int check = 0;
    while(((check=fscanf(fp, "%lf %lf %lf", a_p, b_p, c_p)) != 3 && check!=EOF))
    {
        if ( fgetc(fp) == 'q' && fgetc(fp) == '\n' )
        {
            return EXIT;
        }
        printf("Enter three numbers\n");
        flush_buffer_file(fp);
    }
    flush_buffer_file(fp);
    return ACCEPT;
}*/

enum input_result check_quadratic_input_via_file_(struct quadratic_eq * q_eq, FILE * fp)
{

    if (fp == NULL)
    {
        printf("Not found\n");
        return EXIT;
    }
    int check = 0;
    while(((check=fscanf(fp, "%lf %lf %lf", &(*q_eq).a, &(*q_eq).b, &(*q_eq).c)) != 3 && check!=EOF))
    {
        if ( fgetc(fp) == 'q' && fgetc(fp) == '\n' )
        {
            return EXIT;
        }
        printf("Enter three numbers\n");
        flush_buffer_file(fp);
    }
    flush_buffer_file(fp);
    return ACCEPT;
}



