#include <cs50.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidate structure
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Candidate list
candidate candidates[MAX_CANDIDATES];

// Number of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;

    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }

    for (int idx = 0; idx < candidate_count; idx++)
    {
        candidates[idx].name = argv[idx + 1];
        candidates[idx].votes = 0;
        candidates[idx].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");

    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    for (int voter = 0; voter < voter_count; voter++)
    {
        for (int rank = 0; rank < candidate_count; rank++)
        {
            string choice = get_string("Rank %i: ", rank + 1);

            if (!vote(voter, rank, choice))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    while (true)
    {
        tabulate();

        if (print_winner())
        {
            break;
        }

        int minimum = find_min();

        if (is_tie(minimum))
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        eliminate(minimum);

        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }

    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int voter = 0; voter < voter_count; voter++)
    {
        for (int rank = 0; rank < candidate_count; rank++)
        {
            int candidate_index = preferences[voter][rank];

            if (!candidates[candidate_index].eliminated)
            {
                candidates[candidate_index].votes++;
                break;
            }
        }
    }
}

// Print winner if one exists
bool print_winner(void)
{
    int majority = voter_count / 2;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > majority)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }

    return false;
}

// Find minimum vote count among remaining candidates
int find_min(void)
{
    int minimum = voter_count;

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated &&
            candidates[i].votes < minimum)
        {
            minimum = candidates[i].votes;
        }
    }

    return minimum;
}

// Check whether election is tied
bool is_tie(int minvotes)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated &&
            candidates[i].votes != minvotes)
        {
            return false;
        }
    }

    return true;
}

// Eliminate candidate(s) with minimum votes
void eliminate(int minvotes)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == minvotes)
        {
            candidates[i].eliminated = true;
        }
    }
}
