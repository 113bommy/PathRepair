N, K = list(map(int,input().split()))
a = list(map(int,input().split()))

for i in range(N):  a[i] -= K
dp = [[0 for _ in range(5500)] for _ in range(N + 5)]
dp[0][2500] = 1
for i in range(N):
    for j in range(5010):
        if j - a[i] >= 0 :  dp[i + 1][j] += dp[i][j - a[i]]
        dp[i + 1][j] += dp[i][j] 
        
ans = dp[N][2500] - 1
print(ans)