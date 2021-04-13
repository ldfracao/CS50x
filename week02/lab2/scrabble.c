#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// defines string as a pointer to a char
typedef char* string;

// function prototypes
int compute_score(string word);
char* get_string(char *str);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 == score2)
        printf("Tie!\n");
    else if (score1 > score2)
        printf("Player 1 wins!\n");
    else if (score2 > score1)
        printf("Player 2 wins!\n");
}

int compute_score(string word)
{
    // Compute and return score for string
    int score = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
            score += POINTS[word[i] - 'a'];

        if (word[i] >= 'A' && word[i] <= 'Z')
            score += POINTS[word[i] - 'A'];
    }
    
    return score;
}

char* get_string(char *str)
{
    char *user_in = malloc(30 * sizeof(char));

    if (user_in != NULL)
    {
        printf("%s", str);
        fgets(user_in, 30, stdin);
        user_in[strcspn(user_in, "\n")] = '\0';
    }
    
    return user_in;
}