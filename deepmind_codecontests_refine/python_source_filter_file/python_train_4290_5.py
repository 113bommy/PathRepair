import sys
input = sys.stdin.readline
import heapq as hq
t = int(input())
for _ in range(t):
  n,s = map(int,input().split())
  sr = [list(map(int,input().split())) for i in range(n)]
  summn = sum(list(zip(*sr))[0])
  med = n//2+1
  l = 0
  r = s+1
  while l+1<r:
    flg = 0
    x = (l+r)//2
    cost = summn
    q = []
    hq.heapify(q)
    for i in range(n):
      if sr[i][1] >= x:
        hq.heappush(q,-sr[i][0])
    if len(q) < med:
      pass
    else:
      for _ in range(med):
        cost += x+max(x,-hq.heappop(q))
      if cost <= s:
        flg = 1
    if flg:
      l = x
    else:
      r = x
  print(l)