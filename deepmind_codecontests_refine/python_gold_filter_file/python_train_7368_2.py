from collections import defaultdict
import sys

input = lambda: sys.stdin.readline().rstrip()

def ext_euc(a, b):
  x1, y1, z1 = 1, 0, a
  x2, y2, z2 = 0, 1, b
  while z1 != 1:
    d, m = divmod(z2,z1)
    x1, x2 = x2-d*x1, x1
    y1, y2 = y2-d*y1, y1
    z1, z2 = m, z1
  return x1, y1

class mod_int(int):
  def __new__(cls, i=0, *args, **kwargs):
    return int.__new__(cls, i%M, *args, **kwargs)
  
  def __add__(self, x):
    return self.__class__(int.__add__(self, x))
    
  def __sub__(self, x):
    return self.__class__(int.__sub__(self, x))
    
  def __neg__(self):
    return self.__class__(int.__neg__(self, x))
  
  def __mul__(self, x):
    return self.__class__(int.__mul__(self, x))
  
  def __floordiv__(self, x):
    a, b = ext_euc(x, M)
    return self * a
  
  def __invert__(self):
    a, b = ext_euc(self, M)
    return self.__class__(a)
  
  def __pow__(self, x):
    return self.__class__(int.__pow__(self, x, M))

def mex(s):
  for i in range(N+1):
    if i not in s:
      return i

def calc_grundy(e):
  g = {}
  sum_g = defaultdict(mod_int)
  sum_g[0] = (B**(N+1) - B) // (B-1)
  prev = N
  W = B**N
  for i in range(N, 0, -1):
    if i not in e:
      continue
    m = mex({g.get(j, 0) for j in e[i]})
    if m:
      g[i] = m
      W *= B_inv**(prev-i)
      sum_g[g[i]] +=  W
      sum_g[0]  -= W
      prev, W = i, W
  
  return sum_g

def read_edge():
  M = int(input())
  e = defaultdict(list)
  for i in range(M):
    a, b = sorted(map(int, input().split()))
    e[a].append(b)
  return e

def solve(N, edge):
  sum_g = list(map(calc_grundy, edge))
  ret = mod_int(0)
  for gx, sx in sum_g[0].items():
    for gy, sy in sum_g[1].items():
      gz = gx^gy
      sz = sum_g[2][gz]
      if sz:
        ret += sx*sy*sz
  return ret


M = 998244353
B = mod_int(10) ** 18
B_inv = ~B
N = int(input())

edge = [read_edge() for i in range(3)]

print(solve(N, edge))
