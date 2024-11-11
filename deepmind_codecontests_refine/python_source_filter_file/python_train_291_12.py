class UF():
  def __init__(self, N):
    self.parents = [-1] * (N+1)
    self.weight = [0] * (N+1)

  def union(self, f, t, w):
    w += self.weight[f]
    w -= self.weight[t]

    p1 = self.find(f)
    p2 = self.find(t)
    if p1 == p2:
      return

    if self.parents[p1] > self.parents[p2]:
      p1,p2 = p2,p1
      # w = -w
    self.parents[p1] += self.parents[p2]
    self.weight[p2] = w
    self.parents[p2] = p1

  def find(self, x):
    if self.parents[x] < 0:
      return x
    else:
      y = self.find(self.parents[x])
      self.weight[x] += self.weight[self.parents[x]]
      self.parents[x] = y
      return y

  def compare_weight(self, x, y):
    self.find(x); self.find(y)
    return abs(self.weight[y] - self.weight[x])

  def same(self, n1, n2):
    # import pdb; pdb.set_trace()
    return self.find(n1) == self.find(n2)

N,M = map(int, input().split())
uf = UF(N)
flg = True
for _ in range(M):
  l,r,d = map(int, input().split())
  if uf.same(l, r):
    if uf.compare_weight(l,r) != d:
      flg = False
      break
  else:
    uf.union(l,r,d)

print('Yes') if flg else print('No')