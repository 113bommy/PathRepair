from heapq import heappop,heappush
from collections import defaultdict
t = int(input())
for i in range(t):
  n,a,b,c,d=map(int,input().split())
  q=[(0,n)]
  memo = defaultdict(int)
  while q:
    s,p = heappop(q)
    if memo[p]:
      continue
    memo[p] = 1
    if p == 0:
      print(s)
      break
    heappush(q,(s+d*p,0))
    if p & 1:
      heappush(q,(s+d+a, p//2))
      heappush(q,(s+d+a, p//2+1))
    else:
      heappush(q,(s+a, p//2))
    if p % 3:
      heappush(q,(s+d*(p%3)+b, p//3))
      heappush(q,(s+d*(-p%3)+b, p//3+1))
    else:
      heappush(q,(s+b, p//3))
    if p % 5:
      heappush(q,(s+d*(p%5)+c, p//5))
      heappush(q,(s+d*(-p%5)+c, p//5+1))
    else:
      heappush(q,(s+c, p//5))
    
