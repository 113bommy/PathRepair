H,W = map(int,input().split())
mod = 10**9+7
M = []
for i in range(H):
    M.append(input())
dp = [[0 for i in range(W)] for j in range(H)]
dp[0][0] = 1
for i in range(H):
    for j in range(W):
        if i != H-1 and M[i+1][j] == '.':
            dp[i+1][j] += dp[i][j] % mod
        if j != W-1 and M[i][j+1] == '.':
            dp[i][j+1] += dp[i][j] % mod
print(dp[-1][-1]%mod)