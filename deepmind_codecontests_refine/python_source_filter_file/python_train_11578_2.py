import sys
input = sys.stdin.readline
import bisect
m,n,k,t = map(int,input().split())
ag = list(map(int,input().split()))
ag.sort()
lrd = [list(map(int,input().split())) for i in range(k)]
lrd.sort()
lf = 0
rg = m+1
while lf+1<rg:
  x = (lf+rg)//2
  agl = ag[m-x]
  lr = []
  for l,r,d in lrd:
    if d > agl:
      if lr and lr[-1][1] < l:
        lr.append([l,r])
      elif lr:
        lr[-1][1] = max(lr[-1][1],r)
      else:
        lr.append([l,r])
  ans = n+1
  if lr:
    for l,r in lr:
      ans += (r-l)*2
  if ans > t:
    rg = x
  else:
    lf = x
print(lf)