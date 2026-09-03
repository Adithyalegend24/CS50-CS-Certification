#include <cs50.h>
#include <stdio.h>

int get_change(void);
int count_quarters(int amount);
int count_dimes(int amount);
int count_nickels(int amount);
int count_pennies(int amount);

int main(void)
{
    int amount = get_change();
    int totalCoins = 0;

    int q = count_quarters(amount);
    totalCoins += q;
    amount %= 25;

    int d = count_dimes(amount);
    totalCoins += d;
    amount %= 10;

    int n = count_nickels(amount);
    totalCoins += n;
    amount %= 5;

    int p = count_pennies(amount);
    totalCoins += p;

    printf("%d\n", totalCoins);
}

int get_change(void)
{
    int change;

    while (true)
    {
        change = get_int("Change owed: ");

        if (change >= 0)
        {
            return change;
        }
    }
}

int count_quarters(int amount)
{
    return amount / 25;
}

int count_dimes(int amount)
{
    return amount / 10;
}

int count_nickels(int amount)
{
    return amount / 5;
}

int count_pennies(int amount)
{
    return amount;
}
