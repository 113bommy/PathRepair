N = int(input())
A = list(map(int,input().split()))
K = 2 if N%2 else 1
INF = float('inf')
dp = [[[-INF]*2 for _ in range(K+1)] for _ in range(N+1)]
dp[0][K][0] = 0 #dp[i][can_skip][must_skip]
for i,a in enumerate(A):
    for k in range(K,-1,-1):
        dp[i+1][k][0] = max(dp[i+1][k][0], dp[i][k][1])
        dp[i+1][k][1] = max(dp[i+1][k][1], dp[i][k][0] + a)
        if k:
            dp[i+1][k-1][0] = max(dp[i+1][k-1][0], dp[i][k][0])
print(max(max(row) for row in dp[-1]))