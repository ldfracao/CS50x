#include <stdio.h>
#include <stdlib.h>

int     input_numbers(char *str)
{
    int i;

    i = 0;

    while (str[i] != '\n')
    {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return 1;
    }
    return 0;
}

int main(void)
{
    // TODO: Prompt for start size
    char *start = malloc(10 * sizeof(char));

    do
    {
        printf("Enter start size: ");
        fgets(start, 10, stdin);

    } while (input_numbers(start) == 1);
    

    // TODO: Prompt for end size

    // TODO: Calculate number of years until we reach threshold

    // TODO: Print number of years
}