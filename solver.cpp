#include "solver.h"
#include "utilities.h"
#include <math.h>
#include <stdio.h>
#include <cassert>
#include "input_checker.h"

struct TestData
    {
        double a, b, c;
        double x1_ref, x2_ref;
        int roots_ref;
        const char * name;
    };

struct fileTestData
    {
        double a, b, c;
        double x1_ref, x2_ref;
        int roots_ref;
        int testNumber;
    };

enum equation_solver_result solve_quadratic_equation(double a, double b, double c, double * x1_p, double * x2_p)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1_p!=NULL);
    assert(x2_p!=NULL);

    double D = 0.0;
    if(isEqual(a, 0.0) == true)
    {
        return solve_linear_equation(b, c, x1_p);
    }
    else
    {
        D=b*b - 4.0*a*c;
        if(D<0.0)
        {
            return NO_ROOTS;
        }
        else if(isEqual(D, 0.0) == true)
        {

            *x1_p = (-b)/(2*a);
            if(isEqual(*x1_p, 0.0) == true)
            {
                *x1_p = 0.0;
            }
            return ROOT_1;
        }
        else
        {
            assert(D>0.0);
            *x1_p = ( (-b)+sqrt(D) )/(2*a);
            *x2_p = ( (-b)-sqrt(D) )/(2*a);
            if(isEqual(*x1_p, 0.0) == true)
            {
                *x1_p = 0.0;
            }
            if(isEqual(*x2_p, 0.0) == true)
            {
                *x2_p = 0.0;
            }
            return ROOTS_2;
        }
    }

}

enum equation_solver_result solve_linear_equation(double b, double c, double * x1_p)
{
    assert(x1_p!=NULL);

    assert(isfinite(c));
    assert(isfinite(b));

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

/*int test_quadratic_equation_solver(double a, double b, double c, double x1_ref, double x2_ref, int roots_ref, int test_number)
{
    double x1 = 0.0;
    double x2 = 0.0;

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(a!=NULL);
    assert(b!=NULL);
    assert(c!=NULL);
    assert(x1_ref!=NULL);
    assert(x2_ref!=NULL);
    assert(roots_ref!=NULL);
    assert(test_number!=NULL);

    int roots = solve_quadratic_equation(a, b, c, &x1, &x2);
    if (compare_f(x1,x1_ref) != EQUAL)
    {
        printf("Test %d failed: (x1=%lf) != (x1_ref=%lf)\n", test_number, x1, x1_ref);
        return 0;
    }
    else if (compare_f(x2,x2_ref) != EQUAL)
    {
        printf("Test %d failed: (x2=%.6lf) != (x2_ref=%.6lf)\n", test_number, x2, x2_ref);
        return 0;
    }
    else if (compare_f(roots,roots_ref) != EQUAL)
    {
        printf("Test %d failed: (roots=%d) != (roots_ref=%d)\n", test_number, roots, roots_ref);
        return 0;
    }
    else
    {
        return 1;
    }
}*/

/*void input_test_quadratic_equation_solver(void)
{
    test_quadratic_equation_solver(3.0, -2.0, -1.0, 1.0, -0.3333333333333, 2, 1);//test 1
    test_quadratic_equation_solver(5.0, -2.0, -3.0, 1.0, -0.6, 2, 2);//test 2
    test_quadratic_equation_solver(0.0, 0.0, 0.0, 0.0, 0.0, 0, 3);//test 3
    test_quadratic_equation_solver(0.0, 0.0, 3.0, 0.0, 0.0, -1, 4);//test 4
    test_quadratic_equation_solver(0.0, 3.0, 0.0, 0.0, 0.0, 1, 5);//test 5
    test_quadratic_equation_solver(0.0, 1.0, -8.0, 8.0, 0.0, 1, 6);//test 6
    return;
}*/

void run_test(void)
{
    struct TestData allData[] = { {.a = 3.0, .b = -2.0, .c = -1.0, .x1_ref = 1.0, .x2_ref = -0.3333333333333, .roots_ref = 2, .name = "Test_1"},
                            {.a = 5.0, .b = -2.0, .c = -3.0, .x1_ref = 1.0, .x2_ref = -0.6, .roots_ref = 2, .name = "Test_2"},
                            {.a = 0.0, .b = 0.0, .c = 0.0, .x1_ref = 0.0, .x2_ref = 0.0, .roots_ref = 0, .name = "Test_3"},
                            {.a = 0.0, .b = 0.0, .c = 3.0, .x1_ref = 0.0, .x2_ref = 0.0, .roots_ref = -1, .name = "Test_4"},
                            {.a = 0.0, .b = 3.0, .c = 0.0, .x1_ref = 0.0, .x2_ref = 0.0, .roots_ref = 1, .name = "Test_5"},
                            {.a = 0.0, .b = 1.0, .c = -8.0, .x1_ref = 8.0, .x2_ref = 0.0, .roots_ref = 1, .name = "Test_6"}
                          };

    for (int i = 0; i< sizeof(allData) / sizeof(TestData); i++)
    {
        compare_with_ref_quadratic_equation_solver(&allData[i]);
    }
}

void check_input_from_fileWithTests(FILE * fp, int nStrings)
{
    fseek(fp, 0L, SEEK_SET);
    struct fileTestData fileData[100] = {};
    for (int i = 0; i < nStrings; i++)
    {
        fscanf(fp, "%lf %lf %lf %lf %lf %d %d", &(fileData[i].a), &(fileData[i].b), &(fileData[i].c), &(fileData[i].x1_ref), &(fileData[i].x2_ref), &(fileData[i].roots_ref), &(fileData[i].testNumber));
        flush_buffer_file(fp);
        compare_with_ref_via_file_quadratic_equation_solver(&fileData[i]);
    }
    return;
}

void compare_with_ref_quadratic_equation_solver(struct TestData * data)
{
    double x1 = 0.0;
    double x2 = 0.0;
    int roots = 0;
    roots = solve_quadratic_equation( (*data).a, (*data).b, (*data).c, &x1, &x2);
    if ((isEqual( (*data).x1_ref, x1)) == false)
    {
        printf("%s failed: (x1=%lf) != (x1_ref=%lf)\n", (*data).name, x1, (*data).x1_ref);
    }
    if ((isEqual( (*data).x2_ref, x2)) == false)
    {
        printf("%s failed: (x2=%lf) != (x2_ref=%lf)\n", (*data).name, x2, (*data).x2_ref);
    }
    if ((isEqual( (*data).roots_ref, roots)) == false)
    {
        printf("%s failed: (roots=%d) != (roots_ref=%d)\n", (*data).name, roots, (*data).roots_ref);
    }
    else
    {
        printf("%s success\n", (*data).name);
    }
    return;
}

void compare_with_ref_via_file_quadratic_equation_solver(struct fileTestData * data)
{
    double x1 = 0.0;
    double x2 = 0.0;
    int roots = 0;
    roots = solve_quadratic_equation( (*data).a, (*data).b, (*data).c, &x1, &x2);
    if ((isEqual( (*data).x1_ref, x1)) == false)
    {
        printf("Test %d failed: (x1=%lf) != (x1_ref=%lf)\n", (*data).testNumber, x1, (*data).x1_ref);
    }
    if ((isEqual( (*data).x2_ref, x2)) == false)
    {
        printf("Test %d failed: (x2=%lf) != (x2_ref=%lf)\n", (*data).testNumber, x2, (*data).x2_ref);
    }
    if ((isEqual( (*data).roots_ref, roots)) == false)
    {
        printf("Test %d failed: (roots=%d) != (roots_ref=%d)\n", (*data).testNumber, roots, (*data).roots_ref);
    }
    return;
}
