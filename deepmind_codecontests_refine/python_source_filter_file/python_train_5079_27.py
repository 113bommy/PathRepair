from math import ceil
from bisect import bisect_right
n,d,a=map(int,input().split())
xh=[list(map(int,input().split())) for i in range(n)]
xh.sort()
imos=[0]*(n+1)
x=[]
for i in range(n):
  x.append(xh[i][0])
ans,cnt=0,0
for i in range(n):
  cnt+=imos[i]
  hp=xh[i][1]-cnt*a
  if hp>0:
    cnt+=ceil(hp/a)
    ans+=ceil(hp/a)
  imos[bisect_right(x,x[i]+2*d)]-=ceil(hp/a)
print(ans)