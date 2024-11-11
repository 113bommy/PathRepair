from math import inf
n, m, k = map(int, input().split())
horizontal = []
vertical = []
for _ in range(n):
    horizontal.append(list(map(int, input().split())))
for _ in range(n - 1):
    vertical.append(list(map(int, input().split())))
if k & 1:
    ans = ["-1"] * m
    for _ in range(n):
        print(*ans)
else:
    grid = [[0 for i in range(m)] for j in range(n)]
    for _ in range(k // 2):
        X = [[inf for i in range(m)] for j in range(n)]
        for i in range(n):
            for j in range(m):
                if i >= 1:
                    X[i][j] = min(2 * vertical[i - 1][j] + grid[i - 1][j], X[i][j])
                if i < n - 1:
                    X[i][j] = min(2 * vertical[i][j] + grid[i - 1][j], X[i][j])
                if j >= 1:
                    X[i][j] = min(2 * horizontal[i][j - 1] + grid[i][j - 1], X[i][j])
                if j < m - 1:
                    X[i][j] = min(2 * horizontal[i][j] + grid[i][j], X[i][j])
        #print(X)
        grid = X[:]
    for _ in range(n):
        print(*grid[_])
