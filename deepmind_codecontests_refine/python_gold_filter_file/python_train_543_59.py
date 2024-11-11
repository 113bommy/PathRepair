t = int(input())

for _ in range(t):
    n = int(input())

    if n == 1:
        print(0)
        continue

    h = n // 2
    print(4 * h * (h + 1) * (2 * h + 1) // 3)
