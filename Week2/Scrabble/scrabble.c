#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int LETTER_VALUES[] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
    1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
};

int calculate_score(string text);

int main(void)
{
    string firstPlayer = get_string("Player 1: ");
    string secondPlayer = get_string("Player 2: ");

    int firstScore = calculate_score(firstPlayer);
    int secondScore = calculate_score(secondPlayer);

    if (firstScore > secondScore)
    {
        printf("Player 1 wins!\n");
    }
    else if (secondScore > firstScore)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

int calculate_score(string text)
{
    int total = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        char ch = toupper(text[i]);

        if (isalpha(ch))
        {
            total += LETTER_VALUES[ch - 'A'];
        }
    }

    return total;
}
