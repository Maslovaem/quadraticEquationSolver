#include <stdio.h>
#include <math.h>
#include <ctype.h>
int check_quadratic_input(double *, double *, double *);
int check_linear_input(double *, double *);
char get_first(void);
char check_first_char(void);
int main(void)
{
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double D = 0.0;
    char indicator1 = 'f';
    printf("Enter '1' to solve a quadratic equation, '2' - a linear equation, 'q' - exit.\n");
    if ((indicator1 = check_first_char()) == '1')
    {
        printf("A quadratic equation looks like this: a*x^2 + b*x + c = 0. Enter a,b,c; 'q' - exit.\n");
        while(check_quadratic_input(&a, &b, &c) == 1)
        {
            if(fabs(a-0.0) < 0.0000001)
            {
                if(fabs(b-0.0) < 0.0000001)
                {
                    if(fabs(c-0.0) < 0.0000001)
                    {
                        printf("Any x\n");
                    }
                    else
                    {
                        printf("No such x\n");
                    }
                }
                else
                {
                    printf("x = %.6lf\n",(-c)/b);
                }
            }
            else
            {
                D=b*b - 4.0*a*c;
                if(D<0.0)
                {
                    printf("No such x\n");
                }
                else if(fabs(D-0.0) < 0.0000001)
                {
                    printf("x = %.6lf\n",(-b)/(2*a));
                }
                else
                {
                    printf("x1 = %.6lf, x2 = %.6lf\n", ( (-b)+sqrt(D) )/(2*a), ( (-b)-sqrt(D) )/(2*a));
                }
            }
            printf("Enter a,b,c; 'q' - exit.\n");
        }
    }
    else if (indicator1 == '2')
    {
        printf("A linear equation looks like this: b*x + c = 0. Enter b,c; 'q' - exit.\n");
        while(check_linear_input(&b, &c) == 1)
        {
            if(fabs(b-0.0) < 0.0000001)
            {
                if(fabs(c-0.0) < 0.0000001)
                {
                    printf("Any x\n");
                }
                else
                {
                    printf("No such x\n");
                }
            }
            else
            {
                printf("x = %.6lf\n",(-c)/b);
            }
            printf("Enter b,c; 'q' - exit.\n");
        }
    }

    /*getchar(); //for *.exe
    getchar();
    getchar();*/
    return 0;
}

int check_quadratic_input(double * a_p,double * b_p,double * c_p)
{
    int check = 0;
    while((check=scanf("%lf %lf %lf", a_p, b_p, c_p)) != 3)
    {
        if(getchar()=='q' && check==0 && getchar()=='\n')
        {
            return 0;
        }
        else
        {
            printf("Enter three numbers\n");
            while(getchar() != '\n')
            {
                ;
            }
        }
    }
    return 1;
}

int check_linear_input(double * b_p, double * c_p)
{
    int check = 0;
    while((check=scanf("%lf %lf", b_p, c_p)) != 2)
    {
        if(getchar()=='q'&& check==0 && getchar()=='\n')
        {
            return 0;
        }
        else
        {
            printf("Enter two numbers\n");
            while(getchar()!='\n')
            {
                ;
            }
        }
    }
    return 1;
}

char get_first(void)
{
    char first_char = 'f';
    char temp = 'f';
    first_char = getchar();
    while(isspace(first_char))
    {
        first_char = getchar();
    }
    temp = getchar();
    if(temp != '\n' && temp!=' ')
    {
        first_char = '0';
    }
    while(temp != '\n')
    {
        temp = getchar();
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
