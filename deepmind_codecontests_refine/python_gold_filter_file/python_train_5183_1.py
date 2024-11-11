N=int(input())
A=[0]+list(map(int,input().split()))

dp=[[0]*(N+1) for i in range(3)]

dp[0][1]=-float("inf")
dp[2][1]=A[1]
dp[0][2]=0
dp[1][2]=max(A[1],A[2])
dp[2][2]=-float("inf")

for i in range(3,N+1):
    if i%2==1:
        for j in range(3):
            dp[j][i]=max(dp[j][i-2]+A[i],dp[j][i-1])
    else:
        for j in range(2):
            dp[j][i]=max(dp[j][i-2]+A[i],dp[j+1][i-1])
        dp[2][i]=dp[2][i-2]+A[i]

print(dp[1][N])