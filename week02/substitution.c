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
            printf("Key must cotain 26 characters.\n");
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
    }
    else
    {
        printf("An error occurred.\n");
        return 1;
    }
    free(plaintext);
    return 0;
}
