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

    def union(self, x, y):
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
        """{ルート要素: [そのグループに含まれる要素のリスト], ...}の辞書を返す"""
        groups = {r: [] for r in self.roots()}
        for i in range(self.N):
            groups[self.find(i)].append(i)
        return groups

    def __str__(self):
        return '\n'.join('{}: {}'.format(r, self.members(r)) for r in self.roots())
n=int(input())
r1,c1=map(int,input().split())
r1-=1
c1-=1
r2,c2=map(int,input().split())
r2-=1
c2-=1
grid=[]
for i in range(n):
  grid.append(input())
uf=UnionFind(n*n)
for i in range(n):
  for j in range(n):
    if i<n-1 and grid[i][j]=='0' and grid[i+1][j]=='0':
      uf.union(i*n+j,(i+1)*n+j)
    if j<n-1 and grid[i][j]=='0' and grid[i][j+1]=='0':
      uf.union(i*n+j,i*n+j+1)
if uf.same(r1*n+c1,r2*n+c2):
  print(0)
ans=10**18
for x1 in range(n):
  for y1 in range(n):
    for x2 in range(n):
      for y2 in range(n):
        if uf.same(x1*n+y1,r1*n+c1) and uf.same(x2*n+y2,r2*n+c2):
          ans=min(ans,(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
print(ans)