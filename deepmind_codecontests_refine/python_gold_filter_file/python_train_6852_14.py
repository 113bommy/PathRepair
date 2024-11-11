from itertools import accumulate

class BIT:
  def __init__(self, size):
    self.bit = [0] * (size + 1)
    self.size = size

  def sum(self, i):
    i += 1
    s = 0
    while i > 0:
      s += self.bit[i]
      i -= i & -i
    return s

  def add(self, i, x):
    i += 1
    while i <= self.size:
      self.bit[i] += x
      i += i & -i

N = int(input())
a = list(map(int, input().split()))
lb, ub = -1, 10**9
while ub - lb > 1:
  m = (lb + ub) // 2
  b = [0] * (N+1)
  for i in range(N):
    if a[i] <= m:
      b[i+1] = 1
  b = list(accumulate(b))
  bit_odd = BIT(2*N)
  bit_even = BIT(2*N)
  cnt = 0
  for i in range(N):
    x = N + b[i+1] - i//2 - 1
    y = N + b[i+1] - (i+1)//2 - 1
    if i % 2 == 0:
      bit_even.add(N + b[i] - i//2, 1)
      cnt += bit_even.sum(x) + bit_odd.sum(y)
    else:
      bit_odd.add(N + b[i] - i//2, 1)
      cnt += bit_even.sum(y) + bit_odd.sum(x)
  if cnt < N*(N+1)//4 + 1:
    lb = m
  else:
    ub = m
print(ub)