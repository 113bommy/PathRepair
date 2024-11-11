#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
# inf = float('inf') ;mod = 10**9+7
# mans = inf ;ans = 0 ;count = 0 ;pro = 1
from heapq import heappush,heappop

n,q=map(int,input().split())
STX=[tuple(map(int,input().split())) for i in range(n)]
D=[int(input()) for i in range(q)]
event=[]
for si,ti,xi in STX:
  event.append((si-xi,0,xi))
  event.append((ti-xi,-1,xi))
for di in D:
  event.append((di,1,di))
event.sort()
hq=[]; S=set()
for time, query, number in event:
  if query == 0:
    heappush(hq,number)
    S.add(number)
  elif query == -1:
    S.remove(number)
  else:
    while hq and hq[0] not in S:
      heappop(hq)
    if not hq:
      print(-1)
    else:
      print(hq[0])


