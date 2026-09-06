while True:
    try:
        n = int(input("Height: "))
        if 1 <= n <= 8:
            break
    except ValueError:
        pass

for i in range(n):
    print(" " * (n - i - 1) + "#" * (i + 1))
