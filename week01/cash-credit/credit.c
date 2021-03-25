#include <stdio.h>
#include <stdlib.h>

#define SIZE 17

int     main (void)
{

    char buffer[17];

    int i = 0;

    printf("Enter a credit card number: ");
    fgets(buffer, sizeof buffer, stdin);
    if (buffer[18])
    {
        printf("Please enter 16 number at most: ");
    }
    while (buffer[i] != '\0')
    {
        printf("%c", buffer[i]);
        i++;
    }
}
