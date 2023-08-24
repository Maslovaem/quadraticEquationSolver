#include "utilities.h"
#include <stdio.h>
#include <math.h>


bool isEqual(double d, double e)
{
    const double dif = 0.00000000000009;
    if(fabs(e-d)<=dif)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void flush_buffer(void)
{
    while (getchar()!='\n')
    {
        ;
    }
}

void flush_buffer_file(FILE * fp)
{
    while ( fgetc(fp) != '\n' )
    {
        ;
    }
}
