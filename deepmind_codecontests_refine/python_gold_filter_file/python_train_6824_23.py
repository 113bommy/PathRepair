import sys
n=int(input())
l=list(map(int,input().split()))
a=[]
dp=[[10**43 for j in range(2)]for i in range(n)]
dp[0][0]=0
dp[0][1]=l[0]
for i in range(n):
    a.append(input())
for i in range(1,n):
        t=0
        t1=0
        if a[i]>=a[i-1]:
            t=1
        if a[i]>=a[i-1][::-1]:
            t1=1
        if t*t1==1:
            dp[i][0]=min(dp[i-1][0],dp[i-1][1])
        elif t==1:
            dp[i][0]=dp[i-1][0]
        elif t1==1:
            dp[i][0]=dp[i-1][1]
        t=0
        t1=0
        if a[i][::-1]>=a[i-1]:
            t=1
        if a[i][::-1]>=a[i-1][::-1]:
            t1=1
        if t*t1==1:
            dp[i][1]=min(dp[i-1][0]+l[i],dp[i-1][1]+l[i])
        elif t==1:
            dp[i][1]=dp[i-1][0]+l[i]
        elif t1==1:
            dp[i][1]=dp[i-1][1]+l[i]
if min(dp[n-1][0],dp[n-1][1])==10**43:
    print(-1)
    sys.exit()
print(min(dp[n-1][0],dp[n-1][1]))
        
            
            