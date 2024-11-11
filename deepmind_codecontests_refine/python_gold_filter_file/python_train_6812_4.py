from sys import stdin, stdout
mvalue = 1000


n, m, fold = map(int, stdin.readline().split())
fold += 1
dp = [[[False for k in range(mvalue)] for j in range(m + 1)] for i in range(n + 1)]
values = []
for i in range(n):
    values.append(list(map(int, list(stdin.readline().strip()))))

for j in range(m):
    dp[n - 1][j][values[n - 1][j]] = True

for i in range(n - 2, -1, -1):
    for j in range(m):
        for k in range(mvalue):
            dp[i][j][k] = max(dp[i][j][k], max(dp[i + 1][j + 1][k - values[i][j]], dp[i + 1][j - 1][k - values[i][j]]))

ans = -1
x, y = 0, 0
for j in range(m):
    for k in range(mvalue):
        if dp[0][j][k] and not k % fold and k > ans:
            ans = k
            x = j

steps = []
stdout.write(str(ans) + '\n')
if ans != -1:
    while y != n - 1:
        if dp[y + 1][x - 1][ans - values[y][x]]:
            steps.append('R')
            ans -= values[y][x]
            y += 1
            x -= 1
        else:
            steps.append('L')
            ans -= values[y][x]
            y += 1
            x += 1
            
    stdout.write(str(x + 1) + '\n' + ''.join(steps[::-1]))