
import csv
import sys


def load_database(filename):
    people = []

    with open(filename, "r") as file:
        reader = csv.DictReader(file)

        for record in reader:
            people.append(record)

    return people


def load_sequence(filename):
    with open(filename, "r") as file:
        return file.read().strip()


def count_strs(sequence, markers):
    results = {}

    for marker in markers:
        results[marker] = longest_repetition(sequence, marker)

    return results


def find_person(database, counts):
    for person in database:

        is_match = True

        for marker, value in counts.items():
            if int(person[marker]) != value:
                is_match = False
                break

        if is_match:
            return person["name"]

    return None


def longest_repetition(dna, pattern):
    pattern_len = len(pattern)
    best = 0

    for index in range(len(dna)):

        current = 0
        position = index

        while dna[position:position + pattern_len] == pattern:
            current += 1
            position += pattern_len

        if current > best:
            best = current

    return best


def main():

    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    database = load_database(sys.argv[1])
    dna_sequence = load_sequence(sys.argv[2])

    str_names = list(database[0].keys())[1:]

    observed_counts = count_strs(dna_sequence, str_names)

    result = find_person(database, observed_counts)

    if result:
        print(result)
    else:
        print("No match")


if __name__ == "__main__":
    main()
