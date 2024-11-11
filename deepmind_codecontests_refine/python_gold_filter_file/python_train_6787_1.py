n,m=[int(x) for x in input().split()]
dp=[0]*100001
dp[0]=2
dp[1]=2
dp[2]=4
for i in range(3,100001):
    dp[i]=(dp[i-1]*2-dp[i-3])%(10**9+7)
print((dp[n]+dp[m]-2)%(10**9+7))
