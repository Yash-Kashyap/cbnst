#include <stdio.h>
#include <math.h>
int main(int argc, char **argv)
{
    float truVal, appVal;
    printf("Enter truVal: ");
    scanf("%f", &truVal);
    printf("Enter appVal: ");
    scanf("%f", &appVal);

    float ab,rel,per;

    ab = fabs(truVal-appVal);
    rel = ab/truVal;
    per = rel*100;

    printf("Absolute error: %6.5f\n", ab);
    printf("Relative error: %6.5f\n", rel);
    printf("Percentage error: %6.5f\n", per);

    return 0;
}