#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int     main (int argc, char *argv[])
{
    char *plaintext = malloc(200 * sizeof(char));
    char lowermap[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    //checks for allocation errors
    if (plaintext != NULL)
    {
        // checks if user provided only command line argument
        if(argc != 2)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }

        // checks if key contains 26 characters
        else if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

        // checks if characters are only alphabetical
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

        // checks if key contains any repeated characters
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            for (int j = i; argv[1][j] != '\0'; j++)
            {
                if (argv[1][i] == argv[1][j + 1])
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }

        printf("plaintext: ");
        fgets(plaintext, 200, stdin);
        printf("ciphertext: ");

        // cipher algorithm
        for (int i = 0; plaintext[i] != '\0'; i++)
        {
            if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            {
                for (int j = 0; lowermap[j] != '\0'; j++)
                {
                    if (plaintext[i] == lowermap[j])
                    {
                        plaintext[i] = argv[1][j];
                        break;
                    }
                }
                printf("%c", plaintext[i]);
            }
            else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            {
                for (int j = 0; lowermap[j] != '\0'; j++)
                {
                    if (plaintext[i] == lowermap[j] - 32)
                    {
                        plaintext[i] = argv[1][j] - 32; //- 32 converts lower case into uppercase
                        break;
                    }
                }
                printf("%c", plaintext[i]);
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
    }
    else
    {
        printf("An error occurred.\n");
        return 1;
    }
    free(plaintext);
    return 0;
}
