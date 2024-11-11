
a,s,d,f=map(int,input().split())
dp=[[0]*(f+1) for i in range(d+1)]
dp[a][s]=1
mod=998244353

for x in range(a,d+1):
    for y in range(s,f+1):
        if x==a and y==s:continue
        dp[x][y]=(dp[x-1][y]*y+dp[x][y-1]*x-dp[x-1][y-1]*(x-1)*(y-1))%mod
        
print(dp[d][f])
