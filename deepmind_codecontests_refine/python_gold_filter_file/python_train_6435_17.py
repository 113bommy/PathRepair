MOD=1000000007
K=input()
n=len(K)
D=int(input())

dp=[[[0,0] for j in range(D)] for i in range(10005)]
dp[0][0][1]=1

for i in range(n):
    num = int(K[i])
    for j in range(D):
        for k in range(10):
            dp[i+1][j][0]+=dp[i][(j-k)%D][0]
            dp[i+1][j][0]%=MOD
        dp[i+1][j][1]+= dp[i][(j-num)%D][1]
        for k in range(num):
            dp[i+1][j][0]+=dp[i][(j-k)%D][1]
            dp[i+1][j][0]%=MOD
print((dp[n][0][0]+dp[n][0][1]-1)%MOD)