
/*
#include<stdio.h>
#include<math.h>
float f(float x)
{
    return 2*x-log10(x)-7;
}
float g(float x)
{
    return (log10(x)+7)/2;
}
float g1(float x)
{
    return fabs(1/(2*x*log(10)));
}
int main()
{
    printf("equation is : 2*x-log10(x)-7\n");
    int steps=1,N,flag=0;
    float x0,x1,e;
    printf("Enter initial value: ");
    scanf("%f",&x0);
    printf("Enter no. of iterations: ");
    scanf("%d",&N);
    printf("Enter Error: ");
    scanf("%f",&e);
    if(fabs(g1(x0)<1))
    {
      do
      {
        x1=g(x0);
        printf("%d Iteration, value of x is %f then value of(%f) is %f \n",steps,x0,x0,x1);
        steps = steps+1;
        if(fabs(x1-x0)<=e)
        {
            printf("root = %f",x1);
            flag = 1;
        }
        else
        {
           x0=x1;
        }
        }while(flag<1);
    }
    else
    {
            printf("Incorrect function!!");
    }
}
*/









#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001

float f(float x)
{
    return x*x*x - 3*x -5;
}

float differentiate(float x)
{
    return 3*x*x - 3;
}

int main()
{
    int maxIteration,i;
    float x1,x2,x,x0;
    printf("Enter Maximum no of Iterations\n");
    scanf("%d",&maxIteration);

//......Compute x1 and x2............. 
   
   do
   {
        printf("Enter the value of x1 and x2(starting boundary)");
        scanf("%f%f",&x1,&x2);
        if(f(x1)*f(x2)>0)
        {
           printf("Boundary Values are Invalid\n");
           continue;
        }
        else
        {
            printf("Roots Lie between %f and %f\n",x1,x2);
            break;
        }
    } while(1);

    //find x0
    if(fabs(f(x1)) < fabs(f(x2)))
        x0 = x1;
    else
        x1 = x2;    

    //Apply Successive approximation to find the root b/w x1 and x2
    //..........Find root............   
    for(i=1;i<=maxIteration;i++)
    {
      x = x0 - (f(x0)/differentiate(x0));  
      
      if(fabs(x-x0)<EPSILON)
      {       
            printf("Iterations=%d  Final Root=%f\n",i,x);
           return 0;
      }      
      printf("Iterations=%d  Roots=%f\n",i,x); 
      x0=x;
    }
    printf("Root=%f  Total Iterations=%d",x,--i);
    return 0;
}