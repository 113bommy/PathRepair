n = int(input())
*P, = map(float, input().split())
DP = [[0.0 for j in range(n+1)] for i in range(n+1)]
DP[0][0] = 1.0
for i in range(1, n+1):
    DP[i][0] = DP[i-1][0]*(1-P[i-1])
    for j in range(1, n+1):
        DP[i][j] = DP[i-1][j]*(1-P[i-1])+DP[i-1][j-1]*P[i-1]
print(sum(DP[n][(n+1)//2:]))
