inf = -1000000000
n,h,up,down = map(int,input().split())
a=[int(X) for X in input().split()]
dp=[[0 for i in range(n+1)]for j in range(n+1)]

dp[0][0]=0
s=0

for i in range(n):

    s+=a[i]
    for j in range(i+1):
        if up<=((s-j)%h)<=down:
            bb=1
        else:
            bb=0
        dp[i+1][j]=max(dp[i+1][j],dp[i][j]+bb)
        if up<=((s-j-1)%h)<=down:
            bb=1
        else:
            bb=0
        dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+bb)
print(max(dp[n]))



