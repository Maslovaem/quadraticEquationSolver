#include "input_checker.h"
#include <stdio.h>
#include "utilities.h"
#include "solver.h"
#include "output_analysis.h"

int solver_return = 0;

struct quadratic_eq {
        double a;
        double b;
        double c;
        double x1;
        double x2;
        //enum roots_amnt;
    } q_eq;

enum input_result check_quadratic_input(double * a_p,double * b_p,double * c_p)
{
    int check = 0;
    while((check=scanf("%lf %lf %lf", a_p, b_p, c_p)) != 3)
    {
        if(getchar()=='q' && check==0 && getchar()=='\n')
        {
            return EXIT;
        }
        else
        {
            printf("Enter three numbers\n");
            flush_buffer();
        }
    }
    flush_buffer();
    return ACCEPT;
}


enum input_result check_linear_input(double * b_p, double * c_p)
{
    int check = 0;
    while((check=scanf("%lf %lf", b_p, c_p)) != 2)
    {
        if(getchar()=='q'&& check==0 && getchar()=='\n')
        {
            return EXIT;
        }
        else
        {
            printf("Enter two numbers\n");
            flush_buffer();
        }
    }
    flush_buffer();
    return ACCEPT;
}

enum input_result check_quadratic_input_via_file(double * a_p,double * b_p,double * c_p, FILE * fp)
{

    if (fp == NULL)
    {
        printf("Not found\n");
        return EXIT;
    }
    int check = 0;
    while(((check=fscanf(fp, "%lf %lf %lf", a_p, b_p, c_p)) != 3 && check!=EOF))
    {
        if ( fgetc(fp) == 'q' && fgetc(fp) == '\n' )
        {
            return EXIT;
        }
        printf("Enter three numbers\n");
        flush_buffer_file(fp);
    }
    flush_buffer_file(fp);
    //fclose(fp);
    return ACCEPT;
}

enum input_result check_quadratic_input_via_file_structure(struct quadratic_eq * q_eq, FILE * fp)
{

    if (fp == NULL)
    {
        printf("Not found\n");
        return EXIT;
    }
    int check = 0;
    while(((check=fscanf(fp, "%lf %lf %lf", &(*q_eq).a, &(*q_eq).b, &(*q_eq).c)) != 3 && check!=EOF))
    {
        if ( fgetc(fp) == 'q' && fgetc(fp) == '\n' )
        {
            return EXIT;
        }
        printf("Enter three numbers\n");
        flush_buffer_file(fp);
    }
    flush_buffer_file(fp);
    return ACCEPT;
}

void show_calc_results_using_file_and_struct(FILE * fp)
{
    while(check_quadratic_input_via_file_structure(&q_eq, fp) == ACCEPT)
    {
        solver_return = solve_quadratic_equation(q_eq.a, q_eq.b, q_eq.c, &(q_eq.x1), &(q_eq.x2));
        printf("for a = %lf, b = %lf, c = %lf: \n", q_eq.a, q_eq.b, q_eq.c);
        output_f(q_eq.x1, q_eq.x2, solver_return);
    }
}
