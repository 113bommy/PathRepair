class BIT:
  ini = 0
  def __init__(self, num):
    self.N = 1
    while self.N <= num:
      self.N *= 2
    self.T = [self.ini] * self.N
  def do(self, l, r):
    #合計
    return l + r
  def set(self, L):
    for i in range(len(L)):
      self.update(i, L[i])
  def update(self, x):
    k = x + 1
    self.T[k - 1] += 1
    k += k & -k
    while k <= N:
      self.T[k - 1] += 1
      k += k & -k
  def getV(self, x):
    ans = self.T[x - 1]
    x -= x & -x
    while x != 0:
      ans += self.T[x - 1]
      x -= x & -x
    return ans

import sys
input = sys.stdin.readline
N = int(input())
xy = [list(map(int, input().split())) for i in range(N)]
MOD = 998244353

xy.sort(key = lambda x:x[1])
R = {}
for i in range(N):
  R[xy[i][1]] = i
xy.sort()

LU = [0] * N
LD = [0] * N
RU = [0] * N
RD = [0] * N

Sl = BIT(N)
for i in range(N):
  t = Sl.getV(R[xy[i][1]])
  LU[i] = i - t
  LD[i] = t
  Sl.update(R[xy[i][1]])

Sr = BIT(N)
for i in range(N-1 , -1 , -1):
  t = Sr.getV(R[xy[i][1]])
  RU[i] = (N - 1 - i) - t
  RD[i] = t
  Sr.update(R[xy[i][1]])

ans = 0
PL = [1]
for i in range(N + 1):
  PL.append(PL[-1] * 2 % MOD)

def na(x):
  return PL[x] - 1

for i in range(N):
  t = PL[N - 1]
  t = (t + na(LU[i]) * na(RD[i])) % MOD
  t = (t + na(LD[i]) * na(RU[i])) % MOD
  t = (t + na(LU[i]) * na(LD[i]) * na(RU[i])) % MOD
  t = (t + na(LU[i]) * na(LD[i]) * na(RD[i])) % MOD
  t = (t + na(LU[i]) * na(RD[i]) * na(RU[i])) % MOD
  t = (t + na(LD[i]) * na(RD[i]) * na(RU[i])) % MOD
  t = (t + na(LU[i]) * na(LD[i]) * na(RD[i]) * na(RU[i])) % MOD
  ans = (ans + t) % MOD

print(ans)