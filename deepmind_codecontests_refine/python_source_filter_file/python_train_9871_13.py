class segTree:
  inf = 0
  def __init__(self, num):
    self.N = 1
    while self.N < num:
      self.N *= 2
    self.T = [self.inf] * (2 * self.N - 1)
  def do(self, l, r):
    #最大値
    return max(l, r)
  def set(self, L):
    for i in range(len(L)):
      self.update(i, L[i])
  def update(self, x, v):
    k = x + self.N - 1
    self.T[k] = v
    while k > 0:
      k = (k - 1) // 2
      self.T[k] = self.do(self.T[2*k+1], self.T[2*k+2])
  def getV(self, l, r):
    return self.getVs(l, r, 0, 0, self.N - 1)
  def getVs(self, l, r, k, kl, kr):
    if l <= kl and r >= kr:
      return self.T[k]
    t = (kl + kr) // 2
    if l > t:
      return self.getVs(l, r, 2 * k + 2, t + 1,kr)
    if r < t + 1:
      return self.getVs(l, r , 2 * k + 1, kl, t)
    return self.do(self.getVs(l, r , 2 * k + 1, kl,t),
              self.getVs(l, r , 2 * k + 2, t + 1, kr))

import copy
N = int(input())
h = list(map(int, input().split()))
a = list(map(int, input().split()))

D = segTree(N)
x = copy.deepcopy(h)
x.sort()
R = {}
for i in range(N):
  R[x[i]] = i

DP = [0] * N
for i in range(N):
  DP[i] = D.getV(0, R[h[i]]) + a[i]
  D.update(R[h[i]], DP[i])

print(DP[-1])