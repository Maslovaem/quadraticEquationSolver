#include "utilities.h"
#include "input_checker.h"
#include <stdio.h>
#include <math.h>
#include <cassert>

bool isEqual(double d, double e)
{
    assert(isfinite(d));
    assert(isfinite(e));


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
    flush_buffer_file(stdin);
}

void flush_buffer_file(FILE * fp)
{
    while ( fgetc(fp) != '\n' )
    {
        ;
    }
}

int count_strings(FILE * fp)
{
    int count = 0;
    int ch = 'f';
    if (fp == NULL)
    {
        printf("Not found\n");
    }
    while ( (ch = fgetc(fp)) != EOF )
    {
        if (ch == '\n')
        {
            count++;
        }
    }
    if (count > 100)
    {
        printf("Too much tests\n");
        count = -1;
    }

    return count;
}

void flush_buffer_excluding_first_char(char temp)
{
    while(temp != '\n')
    {
        temp = getchar();
    }
}

bool check_buffer_isspace(void)
{
    char temp = 'f';
    temp = getchar();
    while(temp=='\t' || temp==' ')
    {
        temp = getchar();
    }
    if(temp == '\n')
    {
        return true;
    }
    else
    {
        return false;
    }
}
