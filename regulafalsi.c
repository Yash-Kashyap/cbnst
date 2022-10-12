#include <stdio.h>
#include <math.h>
#define e 2.71828

float func(float x)
{
    return (3*x+sin(x)-pow(e,x));
}

int main()
{
    float a,b,x,aerr;
    int flag = 0, itr=0;
    printf("Equation : 3*x+sin(x)-e^x");
    printf("\nEnter the intervals : ");
    scanf("%f",&a);
    scanf("%f",&b);

    do
    {
        if(func(a)*func(b)<0)
        {
            flag = 1;
            printf("Roots lies between a and b\n");
        }
        else
        {
            printf("Change the intervals\n");
        }
    } while (flag!=1);

    printf("Enter the allowed error : ");
    scanf("%f",&aerr);

    do
    {
        itr++;
        x=a-((b-a)/(func(b)-func(a)))*func(a);
        printf("\n %d iteration, value of x is %f, value of (%f) is %f",itr,x,x,func(x));
        if((fabs(func(x)))<=aerr)
        {
            flag=0;
            printf("\nThe root of the equation is %f after %d iteration",x,itr);
        }
        else if(func(x)*func(a)<0)
        {
            b=x;
        }
        else
        {
            a=x;
        }
    }
    while(flag!=0);

    
return 0;
}