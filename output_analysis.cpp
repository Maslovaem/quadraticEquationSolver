#include "solver.h"
#include <stdio.h>
#include "output_analysis.h"
#include <cassert>
#include <math.h>
#include "input_checker.h"

void output_f(struct quadratic_eq *q_eq, int solver_return)
{
    assert(isfinite( (*q_eq).x1 ));
    assert(isfinite( (*q_eq).x2 ));

    switch (solver_return)
    {
        case NO_ROOTS:
            printf("No such x\n");
            break;
        case INF_ROOTS:
            printf("Any x\n");
            break;
        case ROOT_1:
            printf("x = %.6lf\n", (*q_eq).x1);
            break;
        case ROOTS_2:
            printf("x1 = %.6lf, x2 = %.6lf\n", (*q_eq).x1, (*q_eq).x2);
        default:
            break;
    }
}
