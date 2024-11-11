import itertools

n=int(input())
a=list(map(int,input().split()))

s=[0]+list(itertools.accumulate(a))

dp=[[10**20]*(n+1) for _ in range(n)]
for l in range(n):
    dp[l][l+1]=0
for d in range(2,n+1): 
    for k in range(1,d):
        for i in range(n-d+1):
            j=i+d
            S=s[j]-s[i]
            dp[i][j]=min(dp[i][i+k]+dp[i+k][j],dp[i][j])+S

print(dp[0][n])
