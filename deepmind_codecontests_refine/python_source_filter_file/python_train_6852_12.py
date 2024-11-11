from itertools import accumulate
from collections import defaultdict
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
n = int(input())
a = list(map(int,input().split()))
def jdg(x):
  b = [0 for i in range(n)]
  for i in range(n):
    if a[i] >= x:
      b[i] = 1
    else:
      b[i] = -1
  acc = [0]+list(accumulate(b))
  mn = min(acc)
  mx = max(acc)
  dif = mx-mn
  bit = Bit(dif+2)
  ret = 0
  for i in range(n+1):
    p = acc[i]-mn+1
    ret += bit.sum(p)
    bit.add(p,1)
  return ret
l = 0
r = max(a)+1
while l+1 < r:
  x = (l+r)//2
  if jdg(x) >= (n+1)*n//4+1:
    l = x
  else:
    r = x
print(l)