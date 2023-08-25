#include "solver.h"
#include <stdio.h>
#include "output_analysis.h"
#include <cassert>
#include <math.h>

void output_f(double x1, double x2, int solver_return)
{
    assert(isfinite(x1));
    assert(isfinite(x2));

    switch (solver_return)
    {
        case NO_ROOTS:
            printf("No such x\n");
            break;
        case INF_ROOTS:
            printf("Any x\n");
            break;
        case ROOT_1:
            printf("x = %.6lf\n", x1);
            break;
        case ROOTS_2:
            printf("x1 = %.6lf, x2 = %.6lf\n", x1, x2);
        default:
            break;
    }
}
