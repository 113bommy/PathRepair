from collections import defaultdict
import sys

input = lambda: sys.stdin.readline().rstrip()

M = 998244353 # < (1 << 30)

def mod_inv(a, M=M):
  x1, y1, z1 = 1, 0, a
  x2, y2, z2 = 0, 1, M
  while abs(z1) != 1:
    d, m = divmod(z2, z1)
    x1, x2 = x2-d*x1, x1
    y1, y2 = y2-d*y1, y1
    z1, z2 = m, z1
  return x1*z1%M

R_bits = 30
R = 1 << R_bits
R_dec = R - 1
R2 = pow(R, 2, M)
M_neg_inv = mod_inv(-M, R)

def MR(x):
  b = (x * M_neg_inv) & R_dec
  t = x + b * M
  c = t >> R_bits
  d = c - M
  return d if 0 <= d else c

def Montgomery(x):
  return MR(x*R2)

def mex(s):
  for i in range(N+1):
    if i not in s:
      return i

def calc_grundy(edge):
  grundy = [{} for i in range(3)]
  sum_g = [defaultdict(int, {0:M_W_sum}) for i in range(3)]
  M_W = M_W_last
  for i in range(N, 0, -1):
    for g, s, e in zip(grundy, sum_g, edge):
      if i in e:
        m = mex({g.get(j, 0) for j in e[i]})
        if m:
          g[i] = m
          s[g[i]] +=  M_W
          s[0] -=  M_W
    M_W = MR(M_W * M_B_inv)
  return sum_g

def read_edge():
  M = int(input())
  e = defaultdict(list)
  for i in range(M):
    a, b = sorted(map(int, input().split()))
    e[a].append(b)
  return e

N = int(input())
B = pow(10, 18, M)
M_B_inv = Montgomery(mod_inv(B))
M_W_last = Montgomery(pow(B, N, M))
M_W_sum = MR((M_W_last - Montgomery(1)) * MR(Montgomery(B) * Montgomery(mod_inv(B-1))))

edge = [read_edge() for i in range(3)]
sum_g = calc_grundy(edge)
ans = 0
for gx, sx in sum_g[0].items():
  for gy, sy in sum_g[1].items():
    gz = gx^gy
    sz = sum_g[2][gz]
    if sz:
      ans += MR(MR(sx*sy)*sz)
print(MR(ans))
