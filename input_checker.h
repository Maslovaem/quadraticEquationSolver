#include <cstdio>

#ifndef INPUT_CHECKER_H
#define INPUT_CHECKER_H

struct quadratic_eq {
        double a;///<coefficient a in a quadratic equation ax^2+bx+c=0
        double b;///<coefficient b
        double c;///<coefficient c
        double x1;///<the first root
        double x2;///<the second root
    };

///Possible outcomes
enum input_result { EXIT,   ///<the value is not accepted
                    ACCEPT  ///<the value is accepted
                    };

/**
Checks whether the coefficients of the quadratic equation (ax^2 + bx + c = 0) are entered correctly via console
@param[in] struct pointer
@param[out] EXIT - correct input
@param[out] ACCEPT - incorrect input
*/
enum input_result check_quadratic_input(struct quadratic_eq *q_eq);

//input_result check_linear_input(double * b, double * c);

//enum input_result check_quadratic_input_via_file(double * a_p,double * b_p,double * c_p, FILE * fp);

/**
Checks whether the coefficients of the quadratic equation (ax^2 + bx + c = 0) are entered correctly via file using structure
@param[in] struct pointer
@param[in] file pointer
@param[out] EXIT - correct input
@param[out] ACCEPT - incorrect input
*/
enum input_result check_quadratic_input_via_file_(struct quadratic_eq * q_eq, FILE * fp);

/**
Shows calculation results
@param[in] file pointer
*/
//void show_calc_results_using_file_and_struct (FILE * fp);

#define ASSERT(exp)                                                                         \
do {                                                                                        \
        if ( (exp) == 0) {                                                                  \
        fprintf(stderr, "Expression = " #exp " failed, [%s:%d]\n", __FILE__, __LINE__);     \
        abort();                                                                            \
    }                                                                                       \
}                                                                                           \
while(0)



#endif
