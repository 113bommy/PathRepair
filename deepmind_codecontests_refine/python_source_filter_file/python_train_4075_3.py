n, d = int(input()), sorted(map(int, input().split()))

x, y = max(d), 0
for i in range(n - 2, 0, -1):
    if x % d[i] == 0 and d[i] == d[i - 1] or x % d[i] != 0:
        y = d[i]
        break

print(x, y)
