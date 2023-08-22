#include "utilities.h"
#include <stdio.h>
#include <math.h>


enum comparison_result compare_f(double a)
{
    double dif = 0.0000001;
    if(fabs(a-0.0)<dif)
    {
        return EQUAL;
    }
    else if (a>0.0)
    {
        return GREATER;
    }
    else
    {
        return LESS;
    }
}

void flush_buffer(void)
{
    while (getchar()!='\n')
    {
        ;
    }
}
