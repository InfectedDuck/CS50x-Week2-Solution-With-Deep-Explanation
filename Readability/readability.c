#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int letters_count = 0;
    int sentences_count = 0;
    int words_count = 1;
    string text = get_string("Write the text you want to check for grade: ");
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters_count++;
        }
        else if (text[i] == ' ')
        {
            words_count++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences_count++;
        }
    }
    double L = ((double) letters_count / words_count) * 100.0;
    double S = ((double) sentences_count / words_count) * 100.0;
    int index = (int) round(0.0588 * L - 0.296 * S - 15.8);
    if (index>16)
    {
        printf("Grade 16+\n");
    }
    else if (index<=1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n",index);
    }
    return 0;
}
