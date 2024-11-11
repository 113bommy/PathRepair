import sys,os,io
input = sys.stdin.readline
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
r, n = map(int, input().split())
from bisect import *
T,X,Y = [0]*n,[0]*n,[0]*n
for i in range(n):
  T[i],X[i],Y[i] = map(int, input().split())
T = [0]+T; X = [1]+X; Y = [1]+Y
dp = [0]+[-float('inf')]*n
cum_max = [0]*(n+1)
for i,(t,x,y) in enumerate(zip(T[1:],X[1:],Y[1:])):
  max_dist = max(x-1,r-x)+max(y-1,r-y)
  if t-max_dist<0:
    ind = 0
  else:
    ind = bisect_left(T,t-max_dist)
    dp[i+1] = cum_max[ind-1]+1
  for j in range(i,max(-1,ind-1),-1):
    if dp[j]<0:
      continue
    dist = abs(X[i+1]-X[j])+abs(Y[i+1]-Y[j])
    if dist<=T[i+1]-T[j]:
      dp[i+1] = max(dp[i+1], dp[j]+1)
      if dp[i+1]>cum_max[j]:
        break
  cum_max[i+1] = max(cum_max[i],dp[i+1])
ans = max(dp)
print(ans)