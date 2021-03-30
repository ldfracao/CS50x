#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main (int argc, char *argv[])
{
    char *plaintext = malloc(20 * sizeof(char));
    int key = 0;
    char *endp = NULL;
    
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
            {
                continue;
                
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        //converts key chars into an int
        key = strtoimax(argv[1], &endp, 10);

        printf("plaintext: ");
        fgets(plaintext, 20, stdin);
        printf("ciphertext: ");
        printf("\n");
    }
    else
        return 1;

    free(plaintext);
    return 0;
}
