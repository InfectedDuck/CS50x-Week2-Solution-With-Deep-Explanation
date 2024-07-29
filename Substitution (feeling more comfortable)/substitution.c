#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string key=argv[1];
    char cipher[100] = "";
    int letter_count[26]={0};
    if (argc!=2)
    {
        printf("Usage: %s <key>\n",argv[0]);
        return 1;
    }
    else if (strlen(key)!=26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
        if (isalpha(key[i]) == 0)
        {
            printf("INVALID! Non-alphabetic character in key.\n");
            return 1;
        }
        int index = tolower(key[i]) - 'a';
        if (letter_count[index] > 0)
        {
            printf("Duplicate in key!\n");
            return 1;
        }
        letter_count[index]++;
        }
        string plaintext=get_string("plaintext: ");
        for (int j=0;j<strlen(plaintext);j++)
        {
            if (islower(plaintext[j]))
            {
                int index=plaintext[j]-'a';
                char cipher1[2]={tolower(key[index]),'\0'};
                strcat(cipher,cipher1);
            }
            else if (isupper(plaintext[j]))
            {
                int index=plaintext[j]-'A';
                char cipher2[2]={toupper(key[index]),'\0'};
                strcat(cipher,cipher2);
            }
            else
            {
                char cipher3[2]={plaintext[j],'\0'};
                strcat(cipher,cipher3);
            }
        }
        printf("ciphertext: %s\n",cipher);
        return 0;
    }
}
