#include <stdio.h>

int main()
{
    double x, y, p;
    scanf("%lf %lf %lf", &x, &y, &p);
    
    printf("$%.2lfNTD\\m2\n", p/x/y);
}