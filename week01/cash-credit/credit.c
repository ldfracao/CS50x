#include <stdio.h>
#include <stdlib.h>

//helper function to check if an input has only numbers
int     input_numbers(char *str)
{
    int i;

    i = 0;

    // fgets terminator character is a new line feed, 10 in the ASCII table
    while (str[i] != 10)
    {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return 1;
    }
    return 0;
}

int     main (void)
{

    char *buffer = malloc(16 * sizeof(char));

    do
    {
        printf("Enter a credit card number: ");
        fgets(buffer, 17, stdin);
    } while (input_numbers(buffer) == 1);
    
    free(buffer);
}
