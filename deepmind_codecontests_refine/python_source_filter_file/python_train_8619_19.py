#13:12
n,q = map(int,input().split())
import heapq
import sys
input = sys.stdin.readline
event = []
for _ in range(n):
  s,t,x = map(int,input().split())
  heapq.heappush(event,[s-x,t-x,x])
t = 0
now = []
for _ in range(q):
  d = int(input())
  if event:
    while event[0][0] <= d:
      tmp = heapq.heappop(event)
      heapq.heappush(now,[tmp[2],tmp[1]])
      if not event:
        break
  if now:
    while now[0][1] <= d:
      heapq.heappop(now)
      if not now:
        print(-1)
        break
    else:
      print(now[0][0])
  else:
    print(-1)