import sys
input = sys.stdin.readline

from collections import defaultdict

def DD(arg): return defaultdict(arg)

def int_log(n, a):
  count = 0
  while n>=a:
    n //= a
    count += 1
  return count

H,W = list(map(int,input().split()))
data = [list(map(int, input().split())) for _ in range(H)]

class BIT:
  def __init__(self, logn):
    self.n = 1<<logn
    self.data = [0]*(self.n+1)
    self.el = [0]*(self.n+1)
  def sum(self, i):
    s = 0
    while i > 0:
      s += self.data[i]
      i -= i & -i
    return s
  def add(self, i, x):
    # assert i > 0
    self.el[i] += x
    while i <= self.n:
      self.data[i] += x
      i += i & -i
  def get(self, i, j=None):
    if j is None:
      return self.el[i]
    return self.sum(j) - self.sum(i)
  def bisect(self, x):
    w = i = 0
    k = self.n
    while k:
      if i+k <= self.n and w + self.data[i+k] < x:
        w += self.data[i+k]
        i += k
      k >>= 1
    return i+1

dic = DD(int)
for i in range(W):
  dic[i+1] = i+1

members = DD(int)
for i in range(W):
  members[i+1] = 1

B = BIT(int_log(W,2)+1)
for i in range(W):
  B.add(i+1,1)

def calc_prev_valid(x):
  s = B.sum(x-1)
  if s == 0:
    return 0
  else:
    return B.bisect(s)

count_score = DD(int)
count_score[0] = W
score = 0

for i in range(H):
  a,b = data[i]
  now = b

  while now >= a:
    if B.el[now]:
      count_score[now-dic[now]] -= members[now]
      if not B.el[b+1]:
        dic[b+1] = dic[now]
        B.add(b+1,1)
      if b+1 < W+1:
        count_score[(b+1)-dic[b+1]] += members[now]
      B.add(now,-1)
      members[b+1] += members[now]
      members[now] = 0
    now = calc_prev_valid(now)

  while True:
    if count_score[score]:
      print(score+i+1)
      break
    else:
      score += 1
    if score == W:
      for _ in range(H-i):
        print(-1)
      exit()
  if i == 1500:
    exit()