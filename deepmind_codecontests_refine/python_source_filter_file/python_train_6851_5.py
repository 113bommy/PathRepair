N=int(input())
A=[int(input()) for i in range(N)]
B=[0]*N
for i in range(N):
    if A[i]>0:
        if A[i]%2==0:
            B[i]=2
        else:
            B[i]=1
L=[0,2,1,2,0]
dp=[[10**9]*5 for i in range(N+1)]
for k in range(5):
    dp[0][k]=0
for i in range(1,N+1):
    for k in range(5):
        for k1 in range(k+1):
            if 1<=k<=3:
                dp[i][k]=min(dp[i][k],dp[i-1][k1]+abs(L[k]-B[i-1]))
            else:
                dp[i][k]=min(dp[i][k],dp[i-1][k1]+A[i-1])
ans=10**9
#print(B)
#print(dp)
for a in range(5):
    ans=min(ans,dp[N][a])
print(ans)v