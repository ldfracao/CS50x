#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    char *plaintext = malloc(20 * sizeof(char));
    if (plaintext != NULL)
    {
        if(argc != 2)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

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
        printf("plaintext: ");
        fgets(plaintext, 20, stdin);
    }
    free(plaintext);
    return 0;
}
