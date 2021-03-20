#include <stdio.h>

int main()
{
    char height;
do
{
    printf("Height: ");
    scanf("%c", &height);

} while (height <= '0' || height >= '9');
    height = height - 48;
    int count;
    int i;
    int j;
    int m;
    int n;
    int a;
    int b;

    count = 0;
    i = 0;
    j = 1;
    n = 1;
    b = 1;

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
        printf("  ");

        a = height - b;
        while (a < height)
        {
            printf("#");
            a++;
        }
        b++;
        count++;
        printf("\n");
    }
}