# test
class BIT:
  ini = 0
  def __init__(s, num):
    s.N = 1
    while s.N <= num:
      s.N *= 2
    s.T = [s.ini] * s.N
  def set(s, L):
    for i in range(len(L)):
      s.update(i, L[i])
  def update(s, x, n): # xにnを加える
    k = x + 1
    s.T[k - 1] += n
    k += k & -k
    while k <= s.N:
      s.T[k - 1] += n
      k += k & -k
  def getV(s, x): # xまでの和(x含む)
    if x < 0: return 0
    x += 1
    ans = s.T[x - 1]
    x -= x & -x
    while x != 0:
      ans += s.T[x - 1]
      x -= x & -x
    return ans

N, Q = list(map(int, input().split()))
a = list(map(int, input().split()))
Query = [list(map(int, input().split())) for _ in range(Q)]
  
bit = BIT(N)
bit.set(a)

for q in Query:
  if q[0] == 0:
    _, p, x = q
    bit.update(p, x)
  else:
    _, l, r = q
    print(bit.getV(r - 1) - bit.getV(l - 1))