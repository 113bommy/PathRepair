class UnionFind:
    def __init__(self, n):
        self.n = n
        self.parent = [None]*n

    def root(self, x):
        if self.parent[x] == None:
            return x
        else:
            return self.root(self.parent[x])

    def union(self, x, y):
        x0 = self.root(x)
        y0 = self.root(y)
        if x0 == y0:
            return
        if x0 > y0:
            x0, y0 = y0, x0
        self.parent[y0] = x0


n = int(input())
m = 10**5
uf = UnionFind(2*m)
X, Y = [], []
for i in range(n):
    x, y = map(int, input().split())
    X.append(x-1)
    Y.append(y-1+m)
    uf.union(x-1, y-1+m)
R = {}
for x, y in zip(X, Y):
    r = uf.root(x)
    try:
        R[r][0].add(x)
        R[r][1].add(y)
    except:
        R[r] = [{x}, {y}]
ans = 0
for r in R.keys():
    ans += len(R[r][0])*len(R[r][1])
print(R)
print(ans-n)
