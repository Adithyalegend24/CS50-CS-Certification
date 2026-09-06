from math import floor


def get_letter_count(text):
    total = 0

    for ch in text:
        if ch.isalpha():
            total += 1

    return total


def get_word_count(text):
    total = 1

    for ch in text:
        if ch == " ":
            total += 1

    return total


def get_sentence_count(text):
    total = 0

    for ch in text:
        if ch in ".!?":
            total += 1

    return total


text = input("Text: ")

letters = get_letter_count(text)
words = get_word_count(text)
sentences = get_sentence_count(text)

avg_letters = (letters * 100.0) / words
avg_sentences = (sentences * 100.0) / words

grade = round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8)

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
