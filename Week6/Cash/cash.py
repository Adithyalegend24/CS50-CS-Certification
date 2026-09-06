while True:
    try:
        dollars = float(input("Change owed: "))
        if dollars >= 0:
            break
    except ValueError:
        pass

cents = round(dollars * 100)

coins = 0

for coin in [25, 10, 5, 1]:
    coins += cents // coin
    cents %= coin

print(coins)
