#include <cstdio>
#include <stdbool.h>

#ifndef UTILITIES_H
#define UTILITIES_H

//enum comparison_result {NOT_EQUAL, EQUAL};

/**
Checks whether two values are equal
@param[in] first value
@param[in] second value
@param[out] EQUAL
@param[out] NOT_EQUAL
*/
bool isEqual(double d, double e);

/**
Flushes buffer
*/
void flush_buffer(void);

/**
Ignores other symbols in a string after correct input (in a file)
@param[in] file pointer
*/
void flush_buffer_file(FILE * fp);

/**
Counts strings in a file
@param[in] file pointer
@param[out] amount of strings
*/
int count_strings(FILE * fp);

/**
Flushes buffer if current symbol is not '\ n'
@param[in] current char
*/
void flush_buffer_excluding_first_char(int temp);

/*Checks if any of the rest characters in the buffer are space characters
@param[out] true if al the rest characters in the buffer are space characters
*/
bool check_buffer_isspace(void);

/*
Compares two strings
@param[in] the fist const string
@param[in] the second const string
@param[out] the fist const string
*/
bool MyStrcmp(const char *str1, char *str2);

#endif
