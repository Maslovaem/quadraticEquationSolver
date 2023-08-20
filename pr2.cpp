#include <stdio.h>
#include <math.h>
int main(void)
{
    double a,b,c;
    double D;
    while(scanf("%lf %lf %lf",&a,&b,&c)==3)
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
                printf("x1 = %.6lf, x2 = %.6lf", ((-b)+sqrt(D))/(2*a), ((-b)-sqrt(D))/(2*a));
            }
        }
    }
    /*getchar(); //for *.exe
    getchar();
    getchar();*/
    return 0;
}

