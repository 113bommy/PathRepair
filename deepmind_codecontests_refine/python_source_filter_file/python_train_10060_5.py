class BIT:
  def __init__(self, n):
  
    self.n = n  
    self.tree = [0]*(n+1)
    
  def __setitem__(self, i, v):

    while i <= self.n:
      self.tree[i] += v
      i += i&-i
      
  def __getitem__(self, i):
    
    p = 0

    while i > 0:
      p += self.tree[i]
      i -= i&-i
    return p
    
def lInt(d = " "): return [int(i) for i in input().split(d)]

n, *t = lInt()
p = lInt()
b = BIT(n+1)
rec = [0]*(n+1); block = [0]*(n+1)
ans = 1e10; maxi = 0; fix = 0; best = 0

for i in range(0, n):
  v = p[i]
  b[v] = 1
  g = i-b[v-1]
  rec[v] = g == 0
  fix += g == 0
  block[maxi] += g == 1
  maxi = max(maxi, v)
for i in range(1, n+1):
  tot = fix+block[i]-(rec[i] == 1)

  if tot > best:
    best = tot
    ans = i
print(ans)
  


