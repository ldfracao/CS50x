#include <stdio.h>

int main (void) 
{
    float change;
    char ch;
    char buffer[50];

    // input filter, doesn't filter negative numbers yet
    do 
    {
        printf("How much change: ");
        if (fgets(buffer, sizeof buffer, stdin) == NULL) 
        {
            continue;
        }  
    } while (sscanf(buffer, "%f %c", &change, &ch) != 1);

    // continue logic
}