#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int scores(const char *word);
int main(void)
{
    string word1=get_string("Player1: ");
    string word2=get_string("Player2: ");
    int score1=scores(word1);
    int score2=scores(word2);
    if (score1==score2)
    {
        printf("Tie!\n");
    }
    else if (score1>score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}
int scores(const char *word)
{
    int score=0;
    for (int i=0; i<strlen(word);i++)
    {
        if (isalpha(word[i]))
        {
        score+=points[tolower(word[i])-97];
        }
    }
    return score;
}
