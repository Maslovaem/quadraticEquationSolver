#include <stdio.h>
#include <math.h>
#include <cassert>
#include "utilities.h"
#include "input_checker.h"

bool isEqual(double lhs, double rhs)
{
    ASSERT(isfinite(lhs));
    ASSERT(isfinite(rhs));

    const double DIF = 0.00000000000009;
    if(fabs(lhs-rhs) <= DIF)
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

void flush_buffer_file(FILE *fp)
{
    ASSERT(fp != NULL);

    while ( fgetc(fp) != '\n' )
    {
        ;
    }
}

int count_strings(FILE *fp)
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
    if (count > MAX_TESTS_AMOUNT)
    {
        printf("Too much tests\n");
        count = -1;
    }

    return count;
}

void flush_buffer_excluding_first_char(int temp)
{
    ASSERT(temp != NULL);
    while(temp != '\n')
    {
        temp = getchar();
    }
}

bool check_buffer_isspace(void)
{
    int temp = 'f';
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

bool MyStrcmp(const char *str1, const char *str2)
{
    ASSERT(str1 != NULL);
    ASSERT(str2 != NULL);

    size_t i;
    for (i = 0; str2[i]; i++)
    {
        if(str1[i] != str2[i])
        {
            return false;
        }
    }
    return true;
}

void isAboutZero(double *a)
{
    if (isEqual(*a, 0.0))
    {
        *a = 0.0;
    }
}

void MyStrcpy(char *dest, const char *src)
{
    size_t i;
    for (i = 0; src[i]; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}
