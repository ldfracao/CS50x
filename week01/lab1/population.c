#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>

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
    // start and end size variables
    char *start = malloc(100 * sizeof(char));
    char *end = malloc(100 * sizeof(char));

    // helper pointer used in strtoimax function
    char *endp = NULL;

    // variables used in char to int conversion
    int start_conversion;
    int end_conversion;

    int years; // number of years taken
    int born; // number of llamas born in a year
    int died; // number of llamas that died in a year

    years = 0;

    // Prompt for start size and keep asking for input until it contains only numbers
    do
    {
        printf("Start size: ");
        fgets(start, 25, stdin);
        start_conversion = strtoimax(start, &endp, 10);

    } while (input_numbers(start) == 1 || start_conversion < 9);
    
    // Prompt for end size while it contains nothing but numbers or if it is smaller than start size
    do
    {
        printf("End size: ");
        fgets(end, 100, stdin);
        end_conversion = strtoimax(end, &endp, 10);

    } while (input_numbers(end) == 1 || end_conversion < start_conversion);
    
    // Calculate number of years until we reach threshold
    while (start_conversion < end_conversion)
    {
        born = round(start_conversion / 3);
        died = round(start_conversion / 4);
        start_conversion = start_conversion + born - died;
        years++;
    }

    // free malloced variables
    free(start);
    free(end);

    // Print number of years
    printf("%i\n", years);
}