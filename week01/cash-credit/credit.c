#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//helper function to check if an input has only numbers
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

int     main (void)
{

    char *user_input = malloc(16 * sizeof(char));
    int *multiplier = malloc(8 * sizeof(int));

    int j;
    int k;

    k = 0;

    do
    {
        printf("Enter a credit card number: ");
        fgets(user_input, 17, stdin);
    } while (input_numbers(user_input) == 1);

    j = strlen(user_input);
    printf("%i\n", j);

    while (user_input[k] != '\0')
    {
        multiplier[k] = user_input[j - 3];
        j -= 2;
        k++;
    }
    int m = 0;

    while (multiplier[m] != '\0')
    {
        printf("%c\n", multiplier[m]);
        m++;
    }
    
    // printf("%c %c\n", user_input[j - 3], multiplier[k]);

    // while (j >= 0)
    // {
    //     // multiplier[k] = user_input[j - 3] * 2;
    //     j -= 2;
    //     k++;
    // }
    free(user_input);
}
