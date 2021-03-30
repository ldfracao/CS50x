#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main (int argc, char *argv[])
{
    char *plaintext = malloc(200 * sizeof(char));
    char *endp = NULL;
    int key = 0;
    
    if (plaintext != NULL) //checkes for allocation errors
    {
        // check if user provided only command line argument
        if(argc != 2)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        // check if that command line argument contains only numbers
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            if (argv[1][i] >= '0' && argv[1][i] <= '9')
                continue;
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        //converts key chars into an int
        key = strtoimax(argv[1], &endp, 10);

        printf("plaintext: ");
        fgets(plaintext, 200, stdin);
        printf("ciphertext: ");

        // caesar algorithm
        for (int i = 0; plaintext[i] != '\0'; i++)
        {
            if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            {
                plaintext[i] -= 'A';
                plaintext[i] = ((plaintext[i] + key) % 26) + 'A';
                printf("%c", plaintext[i]);
            }
            else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            {
                plaintext[i] -= 'a';
                plaintext[i] = ((plaintext[i] + key) % 26) + 'a';
                printf("%c", plaintext[i]);
            }
            else
                printf("%c", plaintext[i]);
        }        
    }
    else
        return 1;

    free(plaintext);
    return 0;
}
