#include <stdio.h>
#include <math.h>
int get_first(double*,double*, double*);
int main(void)
{
    double a=0.0;
    double b=0.0;
    double c=0.0;
    double D=0.0;
    printf("A quadratic equation looks like this: a*x^2 + b*x + c = 0. Enter a,b,c; 'q' - exit.\n");
    while(get_first(&a,&b,&c)==1)
    {
        if(fabs(a-0.0)<0.0000001)
        {
            if(fabs(b-0.0)<0.0000001)
            {
                if(fabs(c-0.0)<0.0000001)
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
            D=b*b-4.0*a*c;
            if(D<0.0)
            {
                printf("No such x\n");
            }
            else if(fabs(D-0.0)<0.0000001)
            {
                printf("x = %.6lf\n",(-b)/(2*a));
            }
            else
            {
                printf("x1 = %.6lf, x2 = %.6lf\n", ((-b)+sqrt(D))/(2*a), ((-b)-sqrt(D))/(2*a));
            }
        }
        printf("Enter a,b,c; 'q' - exit.\n");
    }
    /*getchar(); //for *.exe
    getchar();
    getchar();*/
    return 0;
}
int get_first(double*a_p,double*b_p,double*c_p)
{
    int check=0;
    while((check=scanf("%lf %lf %lf",a_p,b_p,c_p))!=3)
    {
        if(getchar()=='q'&& check==0 && getchar()=='\n')
        {
            return 0;
        }
        else
        {
            printf("Enter three numbers\n");
            while(getchar()!='\n')
            {
                ;
            }
        }
    }
    return 1;

}
