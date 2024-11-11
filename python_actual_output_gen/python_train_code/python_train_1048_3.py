n = int(input())
p = [list(map(int, input().split())) for i in range(n)]

m = [[0] * n for i in range(n)]

for l in range(2, n + 1):
    for i in range(n - k + 1):
        j = i + l - 1
        m[i][j] = float('inf')
        for k in range(i, j):
            m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + p[i][0] * p[k][1] * p[j][1])

print(m[0][n - 1])