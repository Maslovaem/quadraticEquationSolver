#include <cstdio>
#ifndef SOLVER_H
#define SOLVER_H

/// Possible amount of roots
enum equation_solver_result {NO_ROOTS = -1, ///<no roots
                             INF_ROOTS = 0, ///<infinite amount of roots
                             ROOT_1 = 1, ///<one root
                             ROOTS_2 = 2 ///<two roots
                             };

/**
Solves a quadratic equation
@param[in] struct pointer
@param[out] EXIT - correct input
@param[out] ACCEPT - incorrect input
*/
enum equation_solver_result solve_quadratic_equation(struct quadratic_eq *q_eq);

/**
Solves a linear equation
@param[in] coefficient b
@param[in] coefficient c
@param[in] root pointer
@param[out] EXIT - correct input
@param[out] ACCEPT - incorrect input
*/
enum equation_solver_result solve_linear_equation(double b, double c, double * x1_p);

//int test_quadratic_equation_solver(double a, double b, double c, double x1_ref, double x2_ref, int roots_ref, int test_number);
//void input_test_quadratic_equation_solver(void);

//void compare_with_ref_quadratic_equation_solver(struct TestData * data);

//void run_test(void);

/**
Gets whether file data is correct
@param[in] file pointer
@param[in] amount of strings in the file
*/
void get_input_from_fileWithTests(FILE * fp, int nStrings);

/**
Compares file data with calculation results
@param[in] struct pointer
*/
void compare_with_ref_via_file(struct fileTestData *data);

/*void input_test_linear_equation_solver(void);
int test_linear_equation_solver(double b, double c, double x1_ref, int roots_ref, int test_number);*/

#endif
