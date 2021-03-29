#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

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

    char *user_input = malloc(20 * sizeof(char));
    char *multiplier = malloc(10 * sizeof(char));
    
    int j; //counter used to get every other digit
    int k; // counter used to store every other digit

    k = 0;

    do
    {
        printf("Enter a credit card number: ");
        fgets(user_input, 20, stdin);
    } while (input_numbers(user_input) == 1);

    // initializes j to the length of user's input (terminator included)
    j = strlen(user_input);
    printf("%i\n\n", j);

    // copies only necessary characters from user input to multiplier,  j - 3 because we want to start from second to last digit and strlen() includes the terminator
    while (user_input[k] != '\0')
    {
        multiplier[k] = user_input[j - 3];
        j -= 2;
        k++;
    }
    int m = 0;

    // function to convert chars into ints
    while (multiplier[m] != '\0')
    {
        printf("%c\n", multiplier[m]);
        multiplier[m] = (multiplier[m] - '0') * 2;//converts char to int and mutiplies them by 2
        printf("%i\n", multiplier[m]);
        m++;
    }
    free(user_input);
    free(multiplier);
}
