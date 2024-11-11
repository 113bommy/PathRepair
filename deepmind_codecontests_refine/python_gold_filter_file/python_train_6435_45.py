mod = 10**9+7
K = input()
n = len(K)
D = int(input())
dp = [[[0]*2 for i in range(D)] for _ in range(n)]
for i in range(int(K[0])):
    dp[0][i%D][0] += 1
dp[0][int(K[0])%D][1] += 1
for i in range(n-1):
    for j in range(D):
        for d in range(10):
            dp[i+1][(j+d)%D][0]+=dp[i][j][0]
            dp[i+1][(j+d)%D][0]%=mod
        for d in range(int(K[i+1])):
            dp[i+1][(j+d)%D][0]+=dp[i][j][1]
            dp[i+1][(j+d)%D][0]%=mod
        dp[i+1][(j+int(K[i+1]))%D][1] += dp[i][j][1]
        dp[i+1][(j+int(K[i+1]))%D][1]%=mod
print((dp[-1][0][0]+dp[-1][0][1]-1)%mod)


