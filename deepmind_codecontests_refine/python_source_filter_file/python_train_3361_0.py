import sys
input=sys.stdin.readline

q=int(input())
for _ in range(q):
    n=int(input())
    t=sorted(list(map(int,input().split())))
    inf=10**5
    dp=[[inf for j in range(3*n//2)] for i in range(n+1)]
    dp[0][0]=0
    for i in range(n+1):
        for j in range(3*n//2-1):
            if(i<n):
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+abs(t[i]-(j+1)))
            dp[i][j+1]=min(dp[i][j+1],dp[i][j])
    print(dp[n][3*n//2-1])
    
        