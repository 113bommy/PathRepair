n,k=map(int,input().split())
a=list(map(int,input().split()))
dp=[0]*(k+1)
mod=10**9+7
for i in range(0,a[0]+1):
    dp[i]=1
for i in range(1,len(a)):
    for j in range(k+1):
        dp[j]=(dp[j]+dp[j-1])%mod
    for j in range(k,a[i],-1):
        dp[j]=(dp[j]-dp[j-a[i]-1]+mod)%mod
print(dp[k])