n = int(input())
INF = 10**9
P = [list(map(int, input().split())) for i in range(n)]
m = [[0]*n for i in range(n)]

for l in range(2, n + 1):
    for i in range(n - l + 1):
        j = i + l - 1
        m[i][j] = INF
        for k in range(i, j):
            m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + P[i - 1][0] * P[k][1] * P[j][1])

print(m[0][n - 1])