#include <ctype.h>
#include <stdio.h>
#include "utilities.h"
#include "first_char.h"
#include "first_char.h"


int get_first(void)
{
    int first_char = 'f';
    first_char = getchar();
    while(isspace(first_char))
    {
        first_char = getchar();
    }
    if(getchar() != '\n')
    {
        first_char = '0';
        flush_buffer();
    }
    return first_char;
}

int check_first_char(void)
{
    int temp = 'f';
    while( (temp = get_first()) != '1' && temp != '2' && temp != 'q')
    {
        printf("Enter '1', '2' or 'q'.\n");
    }
    return temp;
}

