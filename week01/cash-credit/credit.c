#include <stdio.h>
#include <stdlib.h>

int     main (void)
{

    char *buffer = malloc(16 * sizeof(char));
    int i = 0;

    printf("Enter a credit card number: ");
    fgets(buffer, 17, stdin);

    if (buffer != NULL)
    {
        while (buffer[i] != '\0')
        {
            printf("%c", buffer[i]);
            i++;
        }
    }
    free(buffer);
}