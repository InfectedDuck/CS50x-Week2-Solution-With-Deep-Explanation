#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Key must be a non-negative integer.\n");
            return 1;
        }
    }

    int k = atoi(argv[1]);
    string p = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0; p[i] != '\0'; i++)
    {
        char c = p[i];

        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + k) % 26 + base;
        }

        printf("%c", c);
    }
    printf("\n");

    return 0;
}
