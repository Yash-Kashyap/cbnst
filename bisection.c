/*
#include<stdio.h>
#include<math.h>

float func(float x)
{
return (x*x*x)-(2*x)-5;
// return x*log10(x)-1.2;
}

int main()
{

printf("\n") ;
float x0,x1, err;
while(1)
{
printf("Enter the value of x0 and x1 : ");
scanf("%f%f",&x0,&x1);
if(func(x0)* func(x1)<0)
{
printf( "Roots lies between given intervals\n");
break;
}
else
{
printf("Wrong intervals try again....");
}
}

printf("Enter allowed error : "); 
scanf("%f",&err);

float x=(x0+x1)/2;
int i=0;
int y=0;


do{
    i++;
    x=(x0+x1)/2 ;

    if(func(x)*func(x1)<0)
    {
         x0=x ;
    }
    else
    {
        x1=x ;
    }
    printf("iteration %d: value of x is %f, value of f(%f) is %f\n",i,x,x,func(x));
    y=x;
}
while(fabs(func(x))>err);
printf("Root of equation after %d interval is: %f\n",i-1,y); 
return 0;
}
*/














//Bisection Method (With Allowed Error Concept)
#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001
float findValueAt(float x)
{
   return x*x*x - 2*x -5;
}

float bisect(float x1,float x2)
{
    return (x1+x2)/2;
}
int main()
{
    int maxIteration,i=1;
    float x1,x2,x3,x;
    printf("Enter Maximum no of Iterations\n");
    scanf("%d",&maxIteration);
    
   do
   {
        printf("Enter the value of x1 and x2(starting boundary->Initial Roots)");
        scanf("%f%f",&x1,&x2);
        if(findValueAt(x1)*findValueAt(x2)>0)
        {
           printf("Roots are Invalid\n");
           continue;
        }
        else
        {
            printf("Roots Lie between %f and %f\n",x1,x2);
            break;

        }
    } while(1);

    //find the mid point
    x = bisect(x1,x2);   

    do
    {
      if(findValueAt(x)*findValueAt(x1)<0)
         x2=x;    
      else
         x1=x;
      printf("Iterations=%d  Roots=%f\n",i,x);   
      x3 = bisect(x1,x2);  
      if(fabs(x3-x)<EPSILON)
      {
          //print root
          printf("Root=%f  Total Iterations=%d",x,i);
          return 0;

      }
      x=x3;  //v.imp
      i++; 
    }while(i<=maxIteration);
    printf("Root=%f  Total Iterations=%d",x,--i);

    return 0;
}