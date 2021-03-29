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

    char *user_input = malloc(20 * sizeof(char));
    int *multiplier = malloc(20 * sizeof(int));
    int *other_digits = malloc(20 * sizeof(int));
    
    int j; //counter used to get every other digit
    int k; // counter used to store every other digit
    int l; //counert used to get other digits
    int m; //counter used to convert char to int
    int n; //counter used to store other digits
    int sum = 0;
    int remainder = 0;

    k = 0;
    m = 0;
    n = 0;

    do
    {
        printf("Enter a credit card number: ");
        fgets(user_input, 25, stdin);
    } while (input_numbers(user_input) == 1);

    // initializes j an dl to the length of user's input (terminator included)
    l = j = strlen(user_input);
    printf("%i\n\n", j);

    // copies only necessary characters from user input to multiplier,  j - 3 because we want to start from second to last digit and strlen() includes the terminator
    while (j >= 3)
    {
        printf("%c ", user_input[k]);
        printf("%i ", j);
        multiplier[k] = user_input[j - 3];
        printf("%i ", k);
        printf("%c \n", multiplier[k]);
        j -= 2;
        k++;
    } 

    // function to convert chars into ints
    while (multiplier[m] != '\0')
    {
        printf("%c ", multiplier[m]);
        multiplier[m] = (multiplier[m] - '0') * 2;//converts char to int and mutiplies them by 2
        printf("%i\n", multiplier[m]);
        m++;
    }

    // copies all other digits
    while(l >= 2)
    {
        other_digits[n] = user_input[l - 2];
        other_digits[n] = other_digits[n] - '0';// converts char to int
        printf("%i \n", other_digits[n]);
        l -= 2;
        n++;
    }
    
    // if a digit multiplied by 2 results in a 2 digit number, calculates the sum of the 2 digits
    
    for (int w = 0; multiplier[w] != '\0'; w++)
    {
        if (multiplier[w] > 9)
        {
            remainder = multiplier[w] % 10;
            multiplier[w] /= 10;
            sum = sum + multiplier[w] + remainder;
            printf("\t%i %i\n", remainder, multiplier[w]);
        }
        else
        {
            sum += multiplier[w];
        }
    }
    printf("\n%i\n", sum);
    for(int b = 0; other_digits[b] != '\0'; b++)
    {
        printf("\n\n\n%i\n\n\n", other_digits[b]);
        sum += other_digits[b];
    }

    printf("%i\n", sum);

    if (sum % 10 == 0)
    {
        // AMEX Cards have 15 digits and start with 34 or 37, 16 because strlen count the \n terminator
        if (strlen(user_input) == 16 && user_input[0] == '3' && (user_input[1] == '4' || user_input[1] == '7'))
        {
            printf("AMEX\n");
        }

        // Masterlixos have 16 digits and start with, 51, 52, 53, 54 or 55
        if ((strlen(user_input) == 17 && user_input[0] == '5') && (user_input[1] == '1' || user_input[1] == '2' || user_input[1] == '3' || user_input[1] == '4' || user_input[1] == '5'))
        {
            printf("Mastercard\n");
        }

        // Visas have 13 or 16 digits and start with 4
        if ((strlen(user_input) == 14 || strlen(user_input) == 17) && user_input[0] == '4')
        {
            printf("Visa\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    free(user_input);
    free(multiplier);
    free(other_digits);
    return 0;
}
