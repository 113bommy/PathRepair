N=int(input())
a = list(map(int, input().split()))

dp=[[0 for i in range(N+1)] for j in range(N+1)]
for i in range(1,N+1):
    dp[i][i]=a[i-1]
for j in range(1,N+1):
    for i in reversed(range(1,N+1)):
        if i>j:
            continue
        if i==j:
            dp[i][j]=a[i-1]
        if i<j:
            dp[i][j]=max(a[i-1]-dp[i+1][j],a[j-1]-dp[i][j-1])
print(dp[1][N]