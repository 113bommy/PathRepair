n, m, x, y = map(int, input().split())

print(x, y)
print(x, 1)
for i in range(1, n+1):
    if (i % 2 == 1):
        for j in range(1, m + 1):
            if ((i == y and j == x) or (i == 1 and j == x)):
                continue
            print(i, j)
    if (i % 2 == 0):
        for j in range(m, 0, -1):
            if ((i == y and j == x) or (i == 1 and j == x)):
                continue
            print(i, j)
