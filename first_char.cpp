#include <ctype.h>
#include <stdio.h>
#include "utilities.h"
#include "first_char.h"
#include "first_char.h"

char get_first(void)
{
    char first_char = 'f';
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

char check_first_char(void)
{
    char temp = 'f';
    while( (temp = get_first()) != '1' && temp != '2' && temp != 'q')
    {
        printf("Enter '1', '2' or 'q'.\n");
    }
    return temp;
}
