N, A = (int(i) for i in input().split())
x = [int(i) for i in input().split()]
sumx = sum(x)
DP = [[[0] * (N+1) for i in range(sumx+1)] for i in range(N+1)]
DP[0][0][0] = 1
for i in range(N):
    for j in range(sumx+1):
        for k in range(i+1):
            if j - x[i] >= 0:
                DP[i+1][j][k+1] += DP[i][j-x[i]][k]
            DP[i+1][j][k] += DP[i][j][k]

res = 0
for i in range(1,N+1):
    if i * A <= sumx:
        res += DP[N][i * A][i]
print(res)