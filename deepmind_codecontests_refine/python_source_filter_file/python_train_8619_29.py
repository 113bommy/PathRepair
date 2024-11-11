import sys
from heapq import heappop,heappush
input = sys.stdin.readline
n,Q = map(int,input().split())
stx = [list(map(int,input().split())) for i in range(n)]
dls = [int(input()) for i in range(Q)]
event = []
for i in range(n):
  s,t,x = stx[i]
  event.append((s-x,1,x))
  event.append((t-x,-1,x))
for i in range(Q):
  d = dls[i]
  event.append((d,2,i))
event.sort()
"""
ans = [-1]*Q
s = set()
hq = []
for t,q,x in event:
  if q == 1:
    s.add(x)
    heappush(hq,x)
  elif q == -1:
    s.remove(x)
  elif q == 2:
    while hq and hq[0] not in s:
      heappop(hq)
    if hq:
      ans[x] = hq[0]
    else:
      ans[x] = -1
print(*ans,sep="\n")
"""