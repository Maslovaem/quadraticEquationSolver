#include "solver.h"
#include "utilities.h"
#include <math.h>
#include <stdio.h>

enum equation_solver_result quadratic_equation_solver(double a, double b, double c, double * x1_p, double * x2_p)
{
    double D = 0.0;
    if(compare_f(a) == EQUAL)
    {
        return linear_equation_solver(b, c, x1_p);
    }
    else
    {
        D=b*b - 4.0*a*c;
        if(compare_f(D) == LESS)
        {
            return NO_ROOTS;
        }
        else if(compare_f(D) == EQUAL)
        {

            *x1_p = (-b)/(2*a);
            return ROOT_1;
        }
        else
        {
            *x1_p = ( (-b)+sqrt(D) )/(2*a);
            *x2_p = ( (-b)-sqrt(D) )/(2*a);
            return ROOTS_2;
        }
    }

}

enum equation_solver_result linear_equation_solver(double b, double c, double * x1_p)
{
    if(compare_f(b) == EQUAL)
        {
            if(compare_f(c) == EQUAL)
            {
                return INF_ROOTS;
            }
            else
            {
                return NO_ROOTS;
            }
        }
        else
        {
            *x1_p=(-c)/b;
            return ROOT_1;
        }
}
