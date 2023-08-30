#include <cstdio>
#ifndef SOLVER_H
#define SOLVER_H

const int LENGTH = 40;
const int POSSIBLE_OUTCOMES = 4;

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

/**
Gets whether file data is correct
@param[in] file pointer
@param[in] amount of strings in the file
*/
void get_input_from_fileWithTests(FILE * fp, int nStrings, int *nFailed_tests);

/**
Compares file data with calculation results
@param[in] struct pointer
*/
void compare_with_ref_via_file(struct fileTestData *data, int *nFailed_tests);

#endif
