#include <stdio.h>

int main()
{
    char height;

    printf("Height: ");
    scanf("%c", &height);

    while (height <= '0' || height >= '9')
    {
        printf("Height: ");
        scanf("%c", &height);
    }
    height = height - 48;
    int count;
    int i;
    int j;
    int m;
    int n;

    count = 0;
    i = 0;
    j = 1;
    n = 1;

    /*
    ** loop to print lines
    */
    while (count < height)
    {
        /*
        ** loop to print spaces
        */
        while (i < height - j)
        {
            printf(" ");
            j++;
        }
        j = 1;
        i++;

        /*
        ** loop to print hashes
        */
        m = height - n;
        while (m < height)
        {
            printf("#");
            m++;
        }
        n++;
        count++;
        printf("\n");
    }
}