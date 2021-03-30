#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int     main (int argc, char *argv[])
{
    char *plaintext = malloc(200 * sizeof(char));

    //checks for allocation errors
    if (plaintext != NULL)
    {
        // checks if user provided only command line argument
        if(argc != 2)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        else if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        for (int i = 0; argv[1][i]; i++)
        {
            if((argv[1][i] >= 'A' && argv[1][i] <= 'Z') || (argv[1][i] >= 'a' && argv[1][i] <= 'z'))
                continue;
            else
            {
                printf("Key must contain only alphabetic characters.\n");
                return 1;
            }
        }
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            for (int j = 0; argv[1][j] != '\0'; j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }

        printf("plaintext: ");
        fgets(plaintext, 200, stdin);
        printf("ciphertext: ");

    }
    else
    {
        printf("An error occurred.\n");
        return 1;
    }
    free(plaintext);
    return 0;
}
