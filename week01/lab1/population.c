#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

// helper function to check if an input has only numbers characters
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
    // Prompt for start size and keep asking for input until it contains only numbers
    char *start = malloc(10 * sizeof(char));
    int start_conversion;
    char *endp = NULL;
    char *end = malloc(10 * sizeof(char));
    int end_conversion;

    do
    {
        printf("Start size: ");
        fgets(start, 10, stdin);
        start_conversion = strtoimax(start, &endp, 10);

    } while (input_numbers(start) == 1 || start_conversion < 9);
    
    // Prompt for end size while it contains nothing but numbers or if it is smaller than start size
    do
    {
        printf("End size: ");
        fgets(end, 10, stdin);
        end_conversion = strtoimax(end, &endp, 10);

    } while (input_numbers(end) == 1 || end_conversion < start_conversion);
    
    // TODO: Calculate number of years until we reach threshold

    // TODO: Print number of years
}