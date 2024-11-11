n, m = map(int, input().split())
p = list(map(int, input().split()))
xy = [list(map(int, input().split())) for _ in range(m)]

class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n)]

    def root(self, i):
        if(self.par[i] == i):
          return i
        else:
          self.par[x] = self.find(self.par[x])
          return self.par[i]

    def union(self, x, y):
        x = self.root(x)
        y = self.root(y)
        self.par[x] = y

    def same(self, x, y):
        return self.root(x) == self.root(y)

uf = UnionFind(n)
for x, y in xy:
    uf.union(x-1, y-1)
ans = 0
for i in range(n):
    if uf.same(i, p[i]-1):
        ans += 1

print(ans)

