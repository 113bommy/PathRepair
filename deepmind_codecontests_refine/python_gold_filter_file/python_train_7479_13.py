class Bit:
  def __init__(self, n):
    self.size = n
    self.tree = [0] * (n + 1)
 
  def sum(self, i):
    s = 0
    while i > 0:
      s += self.tree[i]
      i -= i & -i
    return s

  def add(self, i, x):
    while i <= self.size:
      self.tree[i] += x
      i += i & -i

from itertools import accumulate
import sys
input = sys.stdin.readline
n,k = map(int,input().split())
a = [int(input())-k for i in range(n)]
acc = [0]+list(accumulate(a))
acc_i = []
for i,x in enumerate(acc):
  acc_i.append((x,i+1))
acc_i.sort()
bit = Bit(n+2)
ans = 0
for i in range(n+1):
  x = acc_i[i][1]
  ans += n+1-x+bit.sum(x)
  bit.add(1,-1)
  bit.add(x+1,1)
print(ans)