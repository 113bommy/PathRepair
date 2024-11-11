import math
t = int(input())

for _ in range(t):
    n, m, x, y = map(int, input().split())

    square = [input() for _ in range(n)]

    if y >= 2 * x:
        print(sum(row.count('.') for row in square))
        continue

    cost = 0
    for row in square:
        whites = row.split('*')
        for w in whites:
            cost += len(w) // 2 * y
            if len(w) % 2:
                cost += x

    print(cost)
