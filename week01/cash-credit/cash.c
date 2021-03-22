#include <stdio.h>
#include <math.h>

int main (void) 
{
    float change;
    do
    {
        printf("How much change?: ");
        scanf("%f", &change);
    } while (change < 0);
    
    printf("%f", change);
}