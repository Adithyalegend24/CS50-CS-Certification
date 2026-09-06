#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar k\n");
            return 1;
        }
    }

    int shift = atoi(argv[1]);

    string text = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; text[i] != '\0'; i++)
    {
        char current = text[i];

        if (islower(current))
        {
            char encrypted = ((current - 'a' + shift) % 26) + 'a';
            printf("%c", encrypted);
        }
        else if (isupper(current))
        {
            char encrypted = ((current - 'A' + shift) % 26) + 'A';
            printf("%c", encrypted);
        }
        else
        {
            printf("%c", current);
        }
    }

    printf("\n");
    return 0;
}
