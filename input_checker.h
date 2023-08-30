#include <cstdio>
//#define NDEBUG_

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

/**
Checks whether the coefficients of the quadratic equation (ax^2 + bx + c = 0) are entered correctly via file using structure
@param[in] struct pointer
@param[in] file pointer
@param[out] EXIT - correct input
@param[out] ACCEPT - incorrect input
*/
enum input_result check_quadratic_input_via_file_(struct quadratic_eq *q_eq, FILE *fp, int *string_number);

#ifdef NDEBUG_
#define ASSERT(exp) ((void)0)
#else
#define ASSERT(exp)                                                                                         \
do {                                                                                                        \
        if ( (exp) == 0) {                                                                                  \
        fprintf(stderr, "Expression = " #exp " failed, [%s:%d - %s]\n", __FILE__, __LINE__, __func__);      \
        abort();                                                                                            \
    }                                                                                                       \
}                                                                                                           \
while(0)
#endif

#endif
