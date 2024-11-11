t = int(input())
for i in range(t):
    n, p = [int(j) for j in input().split()]
    for x in range(1, n + 1):
        for y in range(i + 1, n + 1):
            if min(y - x, x + n - y) <= 2:
                print(x, y)
            elif p > 0:
                print(x, y)
                p -= 1
