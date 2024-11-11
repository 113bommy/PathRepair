import sys
input = sys.stdin.readline
n, k = map(int, input().split())
P = list(map(int, input().split()))

INF = 2**31 - 1
N0 = 1 << (n-1).bit_length()
seg_min = [INF]*(N0 << 1)
seg_max = [0]*(N0 << 1)

def update_min(i, x):
    i += N0
    seg_min[i] = x
    while i > 1:
        y = seg_min[i ^ 1]
        if y <= x:
            break
        i >>= 1
        seg_min[i] = x
            
def query_min(l, r):
    res = INF
    l += N0
    r += N0
    while l < r:
        if r & 1:
            res = min(res, seg_min[r-1])
        if l & 1:
            res = min(res, seg_min[l])
            l += 1
        l >>= 1
        r >>= 1
 
    return res

def init_min(original):
    for i, x in enumerate(original):
        update_min(i, x)
        
def update_max(i, x):
    i += N0
    seg_max[i] = x
    while i > 1:
        y = seg_max[i ^ 1]
        if y >= x:
            break
        i >>= 1
        seg_max[i] = x
            
def query_max(l, r):
    res = 0
    l += N0
    r += N0
    while l < r:
        if r & 1:
            res = max(res, seg_max[r-1])
        if l & 1:
            res = max(res, seg_max[l])
            l += 1
        l >>= 1
        r >>= 1
 
    return res

def init_max(original):
    for i, x in enumerate(original):
        update_max(i, x)
        
class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def size(self, x):
        return -self.parents[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return len(self.roots())

    def all_group_members(self):
        return {r: self.members(r) for r in self.roots()}

    def __str__(self):
        return '\n'.join('{}: {}'.format(r, self.members(r)) for r in self.roots())

init_min(P)
init_max(P)

uf = UnionFind(n-k+1)

for i in range(n-k):
  m = query_min(i, i+k+1)
  M = query_max(i, i+k+1)
  if m == P[i] and M == P[i+k]:
    uf.unite(i, i+1)

q = -1
s = 0
for i in range(k-1):
  if P[i] < P[i+1]:
    s += 1
if s == k-1:
  q = 0
for i in range(n-k):
  s -= int(P[i] < P[i+1])
  s += int(P[i+k-1] < P[i+k])
  if s == k-1:
    if q == -1:
      q = i+1
    else:
      uf.unite(q, i+1)
ans = uf.group_count()
print(ans)