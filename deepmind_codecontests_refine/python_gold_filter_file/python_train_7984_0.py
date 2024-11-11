import sys
a,m,n=list(map(int,input().split()))
aux=[0]*(a+1)
inf=10**15
dp=[aux.copy() for i in range(n+1)]
m1=10**12
m2=10**12
for i in range(m):
    l,r=list(map(int,input().split()))
    if l<m1:
        m1=l
    for j in range(l,r):
        dp[0][j+1]=inf
s=[]
for i in range(1,n+1):
    x,w=list(map(int,input().split()))
    s.append(tuple([x,w]))
    if x<m2:
        m2=x
if m2>m1:
    print(-1)
    sys.exit()
s.sort()

for i in range(1,n+1):
    x=s[i-1][0]
    w=s[i-1][1]
    for j in range(x+1):
        dp[i][j]=dp[i-1][j]
    for j in range(x+1,a+1):
        if i!=1:
            dp[i][j]=min(dp[0][j]+dp[i][j-1],dp[i-1][j],w*(j-x)+dp[i][x])
        else:
            dp[i][j]=min(dp[0][j]+dp[i][j-1],w*(j-x)+dp[i][x])
            
ans=dp[-1][-1]
if ans>=inf:
    print(-1)
else:
    print(ans)
