import sys,math
from collections import defaultdict,deque
input=sys.stdin.readline



n,x=map(int,input().split())
l=list(map(int,input().split()))
dp=[[[0 for _ in range(2)] for _ in range(2)] for _ in range(len(l))]
#print(dp)  #index in l,is usable or not,is in use or not
dp[0][0][0]=l[0]
dp[0][1][0]=l[0]
dp[0][1][1]=x*l[0]
ans=max(l[0],l[0]*x,0)
for i in range(1,n):
    dp[i][0][0]=max(l[i],l[i]+max(dp[i-1][0][0],dp[i-1][1][1]))
    dp[i][1][0]=max(l[i],l[i]+dp[i-1][1][0])
    dp[i][1][1]=max(l[i]*x,l[i]*x+max(dp[i-1][1][1],dp[i-1][1][0]))
    ans=max(ans,dp[i][0][0],dp[i][1][0],dp[i][1][1])
print(ans)
