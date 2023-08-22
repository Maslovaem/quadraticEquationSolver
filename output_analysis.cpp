#include "solver.h"
#include <stdio.h>
#include "output_analysis.h"

void output_f(double * x1_p, double * x2_p, int solver_return)
{
    switch (solver_return)
    {
        case NO_ROOTS:
            printf("No such x\n");
            break;
        case INF_ROOTS:
            printf("Any x\n");
            break;
        case ROOT_1:
            printf("x = %.6lf\n", *x1_p);
            break;
        case ROOTS_2:
            printf("x1 = %.6lf, x2 = %.6lf\n", *x1_p, *x2_p);
        default:
            break;
    }
}
