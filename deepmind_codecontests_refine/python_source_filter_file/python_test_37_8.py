import math
from sys import stdin, stdout
 
def solve():
  t = int(input())
  while t:
    t -= 1
    n, m = (map(int,input().strip().split()))
    p = {i for i in range(1, n+1)}
    for i in range(m):
      a, b, c = (map(int,input().strip().split()))
      if c in p:
        p.remove(c)
    #print (p)
    ans = list(p)[0]
    for i in range(1, n+1):
      if i != ans:
        print(i, ans)
 
solve()
