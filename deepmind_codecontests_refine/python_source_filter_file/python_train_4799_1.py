from sys import stdin
from math import ceil
n=int(stdin.readline().strip())
s=tuple([0]+list(map(int,stdin.readline().strip().split()))+[0])
lim=ceil(n/2)+1
dp=[[100000002 for i in  range(n+1)] for j in range(lim)]
vis=[[False for i in  range(n+1)] for j in range(lim)]
for  i in range(n+1):
    dp[0][i]=0
ans=[0 for i in range(lim-1)]
for i in range(1,lim):
    for j in range(1,n+1):
        x=0
        y=s[j-1]
        if vis[i-1][j-2]:
            y=min(y,s[j-2]-1)
        if y>=s[j]:
            x=y-s[j]+1
        if s[j+1]>=s[j]:
            x+=s[j+1]-s[j]+1
        if j==1:
            if dp[i-1][0]+x<=dp[i][j-1]:
                vis[i][j]=True
                dp[i][j]=dp[i-1][0]+x
            else:
                dp[i][j]=dp[i][j-1]
        else:
            if dp[i-1][j-2]+x<=dp[i][j-1]:
                vis[i][j]=True
                dp[i][j]=dp[i-1][j-2]+x
            else:
                dp[i][j]=dp[i][j-1]
    ans[i-1]=dp[i][-1]
print(*ans)
