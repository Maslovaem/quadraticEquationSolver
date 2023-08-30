#include <math.h>
#include <stdio.h>
#include <assert.h>
#include "solver.h"
#include "utilities.h"
#include "input_checker.h"

struct fileTestData
{
    double a, b, c;
    double x1_ref, x2_ref;
    int roots_ref;
    int testNumber;
};

enum equation_solver_result solve_quadratic_equation(struct quadratic_eq *q_eq)
{
    ASSERT(isfinite(q_eq->a));
    ASSERT(isfinite(q_eq->b));
    ASSERT(isfinite(q_eq->c));

    ASSERT(q_eq!=NULL);

    if(isEqual( (*q_eq).a, 0.0) == true)
    {
        return solve_linear_equation( (*q_eq).b, (*q_eq).c, &(q_eq->x1));
    }
    else
    {
        double D = NAN;
        D = (q_eq->b)*(q_eq->b) - 4.0*(q_eq->a)*(q_eq->c);
        if(isEqual(D, 0.0) == true)
        {

            (*q_eq).x1 = (-(q_eq->b))/(2 * (q_eq->a));
             isAboutZero( &(q_eq->x1) );
            return ROOT_1;
        }
        else if(D<0.0)
        {
            return NO_ROOTS;
        }
        else
        {
            ASSERT(D>0.0);

            (*q_eq).x1 = ( (-(q_eq->b)) + sqrt(D) )/(2 * (q_eq->a));
            (*q_eq).x2 = ( (-(q_eq->b)) - sqrt(D) )/(2 * (q_eq->a));
            isAboutZero( &(q_eq->x1) );
            isAboutZero( &(q_eq->x2) );

            return ROOTS_2;
        }
    }

}

enum equation_solver_result solve_linear_equation(double b, double c, double * x1_p)
{
    ASSERT(x1_p!=NULL);

    ASSERT(isfinite(c));
    ASSERT(isfinite(b));

    if(isEqual(b, 0.0) == true)
        {
            if(isEqual(c, 0.0) == true)
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
            if(isEqual(*x1_p, 0.0) == true)
            {
                *x1_p = 0.0;
            }
            return ROOT_1;
        }
}

void get_input_from_fileWithTests(FILE *fp, int nStrings, int *nFailed_tests)
{
    ASSERT(fp != NULL);
    ASSERT(nStrings != -1);
    ASSERT(nStrings != 0);

    fseek(fp, 0L, SEEK_SET);
    struct fileTestData fileData = {.a = 0.0, .b = 0.0, .c = 0.0, .x1_ref = 0.0, .x2_ref = 0.0, .roots_ref = 0, .testNumber = 0};

    for (int i = 0; i < nStrings; i++)
    {
        fscanf(fp, "%lf %lf %lf %lf %lf %d %d", &(fileData.a),
                                                &(fileData.b),
                                                &(fileData.c),
                                                &(fileData.x1_ref),
                                                &(fileData.x2_ref),
                                                &(fileData.roots_ref),
                                                &(fileData.testNumber));
        flush_buffer_file(fp);
        compare_with_ref_via_file(&fileData, nFailed_tests);
    }
    printf("Amount of failed tests: %d\n", *nFailed_tests);
}

void compare_with_ref_via_file(struct fileTestData *data, int *nFailed_tests)
{
    ASSERT(data!=NULL);
    ASSERT(nFailed_tests!=NULL);

    struct quadratic_eq q_eq = {.a = 0.0, .b = 0.0, .c = 0.0, .x1 = 0.0, .x2 = 0.0};

    q_eq.a = (*data).a;
    q_eq.b = (*data).b;
    q_eq.c = (*data).c;

    int roots = solve_quadratic_equation(&q_eq);
    char roots_amount[POSSIBLE_OUTCOMES][LENGTH] = { {"no roots"}, {"infinite amount of roots"}, {"one root"}, {"two roots"} };
    char roots_str[LENGTH] = "";
    char roots_str_ref[LENGTH] = "";
    for (int i = 0; i < POSSIBLE_OUTCOMES; i++)
    {
        if (roots == i-1)
        {
            MyStrcpy(roots_str, roots_amount[i]);
        }
        if ( (*data).roots_ref == i-1 )
        {
            MyStrcpy(roots_str_ref, roots_amount[i]);
        }
    }

    if (!isEqual( (*data).x1_ref, q_eq.x1) || !isEqual( (*data).x2_ref, q_eq.x2 ) || !isEqual( (*data).roots_ref, roots))
    {
        printf("Test %d failed:\n", (*data).testNumber);
        (*nFailed_tests)++;
        if (isEqual( (*data).x1_ref, q_eq.x1 ) == false)
        {
            printf("\t(x1=%lf) != (x1_ref=%lf)\n", q_eq.x1, (*data).x1_ref);
        }
        if (isEqual( (*data).x2_ref, q_eq.x2 ) == false)
        {
            printf("\t(x2=%lf) != (x2_ref=%lf)\n", q_eq.x2, (*data).x2_ref);
        }
        if (isEqual( (*data).roots_ref, roots) == false)
        {
            printf("\t(roots=%s) != (roots_ref=%s)\n", roots_str, roots_str_ref);
        }
    }
}
