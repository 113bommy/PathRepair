n,m=map(int,input().split())
A=list(int(input()) for i in range(m))+[-1]
dp=[0]*(n+1)
dp[0]=1
j=0
for i in range(1,n+1):
    if i==A[j]:
        dp[i]=0
        j +=1
    else:
        dp[i]=dp[i-1]+dp[i-2]
print(dp[n]%1000000007)