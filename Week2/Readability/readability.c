#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int get_letter_count(string input);
int get_word_count(string input);
int get_sentence_count(string input);

int main(void)
{
    string passage = get_string("Text: ");

    int letters = get_letter_count(passage);
    int words = get_word_count(passage);
    int sentences = get_sentence_count(passage);

    float avgLetters = (letters * 100.0) / words;
    float avgSentences = (sentences * 100.0) / words;

    int grade = round(0.0588 * avgLetters - 0.296 * avgSentences - 15.8);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

    return 0;
}

int get_letter_count(string input)
{
    int total = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (isalpha(input[i]))
        {
            total++;
        }
    }

    return total;
}

int get_word_count(string input)
{
    int total = 1;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
        {
            total++;
        }
    }

    return total;
}

int get_sentence_count(string input)
{
    int total = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        switch (input[i])
        {
            case '.':
            case '!':
            case '?':
                total++;
                break;
        }
    }

    return total;
}
