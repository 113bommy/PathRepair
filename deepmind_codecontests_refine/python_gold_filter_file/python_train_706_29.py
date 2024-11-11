n, k = map(int, input().split())
*A, = map(int, input().split())
p = 10**9+7
DP = [[None for j in range(k+1)] for i in range(n+1)]
for i in range(n+1):
    DP[i][0] = 1
for j in range(1, k+1):
    DP[0][j] = 0
for i in range(1, n+1):
    for j in range(1, k+1):
        DP[i][j] = (DP[i][j-1]+DP[i-1][j]) % p
        if j > A[i-1]:
            DP[i][j] = (DP[i][j]-DP[i-1][j-1-A[i-1]]) % p
print(DP[n][k])
