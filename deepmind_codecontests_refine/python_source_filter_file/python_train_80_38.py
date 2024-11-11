n,m=map(int,input().split())
a=[int(input()) for _ in range(m)]
dp=[0]*(n+2)
dp[0]=1
for i in range(n):
    if i in a:
        continue
    dp[i+1]+=dp[i]
    dp[i+2]+=dp[i]
print(dp[n]%1000000007)