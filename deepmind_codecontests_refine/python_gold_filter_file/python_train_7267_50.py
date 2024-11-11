N = int(input())
a = [int(x) for x in input().split()]

p = [0] * 3
for i in a:
    p[3-i] += 1

dp = [[[0] * (N+1-i-j) for j in range(N+1-i)] for i in range(N+1)]

for i in range(N+1):
    for j in range(N+1-i):
        for k in range(N+1-i-j):
            if i + j + k == 0:
                continue
            if i > 0:
                dp[i][j][k] += dp[i-1][j+1][k] * i
            if j > 0:
                dp[i][j][k] += dp[i][j-1][k+1] * j
            if k > 0:
                dp[i][j][k] += dp[i][j][k-1] * k
            dp[i][j][k] += N
            dp[i][j][k] /= (i + j + k)

print(dp[p[0]][p[1]][p[2]])