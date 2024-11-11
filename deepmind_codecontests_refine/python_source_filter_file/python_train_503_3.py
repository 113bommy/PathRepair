N, A = map(int, input().split())
X = list(map(int, input().split()))
dp = [[0]*(A*N+2) for _ in range(N+2)]
dp[0][0] = 1
for i, x in enumerate(X,start=1):
    for n in reversed(range(i)):
        for k in range(A*i+1):
            if dp[n][k] == 0: continue
            dp[n+1][min(k+x,A*N+1)] += dp[n][k]
print(sum(dp[n][A*n] for n in range(1,N+1)))
