n, k = map(int, input().split())
a, b = [[] for row in range(6)], [[0 for col in range(n + 1)] for row in range(6)]

for i in range(k):
    a[i] = list(map(int, input().split()))
    for j in range(n):
        b[i][a[i][j]] = j

dp = [1] * n
for i in range(n):
    for j in range(i):
        flag = 1
        for x in range(1, k):
            if b[x][a[0][j]] > b[x][a[0][i]]:
                flag = 0
                break
        if flag:
            dp[i] = max(dp[i], dp[j] + 1)
print(dp[n - 1])
