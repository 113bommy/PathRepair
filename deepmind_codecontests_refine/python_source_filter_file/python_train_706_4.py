import sys
n,k=map(int,input().split())
a=list(map(int,input().split()))
I=10**9+7

if sum(a)<k:
    print(0)
    sys.exit()

dp=[[float("inf")]*(k+1) for _ in range(n+1)]
for p in range(k+1):
    dp[0][p]=0
    if a[0]<p:
        dp[1][p]=0
    else:
        dp[1][p]=1
for i in range(1,n):
    s=[0]*(k+2)
    for j in range(k+1):
        s[j+1]=s[j]+dp[i][j]
        dp[i+1][j]=s[j+1]-s[max(0,j-a[(i+1)-1])]

print(dp[n][k]%I)