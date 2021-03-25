#include <stdio.h>
#include <math.h>

int main (void) 
{
    float input;
    int change;
    int rest;
    int totalCoins;
    char *ch;
    char buffer[50];

    totalCoins = 0;
    rest = 0;

    // input filter
    do 
    {
        printf("How much change?\n");
        ch = fgets(buffer, sizeof buffer, stdin);
        if (ch == NULL) 
        {
            break;
        }
    } while (sscanf(buffer, "%f %c", &input, ch) != 1 || input < 0);

    input *= 100;
    change = round(input);

    while (change - rest >= 25)
    {
        rest += 25;
        totalCoins++;
    }
    while (change - rest >= 10)
    {
        rest += 10;
        totalCoins++;
    }
    while (change - rest >= 5)
    {
        rest += 5;
        totalCoins++;
    }
    while (change - rest >= 1)
    {
        rest += 1;
        totalCoins++;
    }
    printf("%i\n", totalCoins);
}