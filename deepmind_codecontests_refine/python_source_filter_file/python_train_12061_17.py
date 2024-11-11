import bisect
N,W=map(int,input().split())
wv=[list(map(int,input().split())) for _ in range(N)]
w1=wv[0][0]

Wlist=[0]+[j*(w1+i) for j in range(1,N+1) for i in range(3*j+1)]
Wlist=sorted(set(Wlist))
LW=len(Wlist)
dp=[[0]*LW for _ in range(N+1)]
#dp[i][j]:N個の物に対して強度(Wlist[j])のバッグ

for i in range(1,N+1):
  w,v=wv[i-1]
  for j in range(LW):
    if w<=Wlist[j]:      
      ind=bisect.bisect_right(Wlist,Wlist[j]-w)-1
      dp[i][j]=max(dp[i-1][j],dp[i-1][ind]+v)
    else:
      dp[i][j]=dp[i-1][j]

ind=bisect.bisect_right(Wlist,W)-1
print(dp[N][ind])