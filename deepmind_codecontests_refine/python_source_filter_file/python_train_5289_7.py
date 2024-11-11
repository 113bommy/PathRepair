import sys
class Bit:
  def __init__(self,n):
    self.size = n
    self.tree = [0]*(n+1)
 
  def sum(self,i):
    s = 0
    while i > 0:
      s += self.tree[i]
      i -= i & -i
    return s

  def add(self,i,x):
    while i <= self.size:
      self.tree[i] += x
      i += i & -i
input = sys.stdin.readline
from collections import defaultdict
mod = 998244353
n = int(input())
p2t = [1]
for i in range(n):
  p2t.append(p2t[-1]*2%mod)
dcy = defaultdict(int)
xy = [list(map(int,input().split())) for i in range(n)]
xy.sort()
yls = list(zip(*xy))[1]
yls = list(yls)
for i in range(n):
  dcy[yls[i]] = i
yls.sort()
yind = [0 for i in range(n)]
for i in range(n):
  ind = dcy[yls[i]]
  yind[ind] = i
xyd = []
for i in range(n):
  xyd.append((i,yind[i]))
ans = 0
bit = Bit(n+1)
"""
for i in range(n):
  x,y = xyd[i]
  upper = n-y-1
  right = n-x-1
  ld = bit.sum(y+1)
  ru = upper+right+ld-n+1
  rd = right-ru
  lu = upper-ru
  p2lu = p2t[lu]
  p2rd = p2t[rd]
  p2ru = p2t[ru]
  p2ld = p2t[ld]
  ans += ((p2lu-1)*(p2rd-1)*(p2t[ld+ru])%mod+(p2ld-1)*(p2ru-1)*(p2t[lu+rd])%mod+
  p2t[n-1]-(p2lu-1)*(p2rd-1)*(p2ld-1)*(p2ru-1)%mod)
  ans %= mod
  bit.add(y+1,1)
print(ans)
"""