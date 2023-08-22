#include "input_checker.h"
#include <stdio.h>
#include "utilities.h"

enum input_result check_quadratic_input(double * a_p,double * b_p,double * c_p)
{
    int check = 0;
    while((check=scanf("%lf %lf %lf", a_p, b_p, c_p)) != 3)
    {
        if(getchar()=='q' && check==0 && getchar()=='\n')
        {
            return EXIT;
        }
        else
        {
            printf("Enter three numbers\n");
            flush_buffer();
        }
    }
    return ACCEPT;
}

enum input_result check_linear_input(double * b_p, double * c_p)
{
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
    return ACCEPT;
}
