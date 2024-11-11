from collections import defaultdict

INF = 2 ** 60
dp = defaultdict(lambda: -INF)

n = int(input())
a = list(map(int, input().split())) + [0] * 10

dp[(0, 0)] = 0
dp[(1, 1)] = a[0]

for i in range(n):
    for j in range(i // 2 - 2, i // 2 + 3):
        dp[(i + 2, j + 1)] = max([dp[(i + 2, j + 1)], dp[(i, j)] + a[i + 1]])
        dp[(i + 1, j)] = max([dp[(i + 1, j)], dp[(i, j)]])

print(dp[(n, n // 2)])
