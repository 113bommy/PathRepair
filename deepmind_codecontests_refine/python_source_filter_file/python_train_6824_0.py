n=int(input())
s=list(map(int,input().split()))
q=[input() for i in range(n)]
q1=[q[i][::-1] for i in range(n)]
maxx=10**12
dp=[[maxx,maxx] for  i in range(n)]
dp[0][0]=0
dp[0][1]=s[0]
for i in range(1,n):

    if q1[i]>=q[i-1]:
        dp[i][1]=dp[i-1][0]+s[i]
    if q1[i]>=q1[i-1]:
        dp[i][1]=min(dp[i][1],dp[i-1][1]+s[i])
    if q[i]>=q1[i-1]:
        dp[i][0]=dp[i-1][1]
    if q[i]>=q[i-1]:
        dp[i][0]=min(dp[i][0],dp[i-1][0])
ans=(min(dp[-1]))
if ans>=maxx:
    print(-1)
else:
    print(ans)
