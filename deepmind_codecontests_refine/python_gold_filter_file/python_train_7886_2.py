class UnionFind():
    def __init__(self, n):
        self.parents = list(range(n))

    def find(self, x):
        if self.parents[x] == x:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        self.parents[y] = x
        
n,m = map(int,input().split())
uf = UnionFind(n)
for i in range(m):
    a,b=map(int,input().split())
    uf.union(a-1,b-1)

size = 0
for i in range(n):
    if uf.parents[i] == i:
        size += 1
print(size-1)