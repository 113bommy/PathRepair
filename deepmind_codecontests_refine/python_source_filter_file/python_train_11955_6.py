N, M = map(int, input().split())
A = list(map(int, input().split()))

class Uf:
    def __init__(self, N, mins):
        self.p = list(range(N))
        self.rank = [0] * N
        self.size = [1] * N
        self.mins = mins
        self.amins = list(range(N))

    def root(self, x):
        if self.p[x] != x:
            self.p[x] = self.root(self.p[x])

        return self.p[x]

    def same(self, x, y):
        return self.root(x) == self.root(y)

    def unite(self, x, y):
        u = self.root(x)
        v = self.root(y)

        if u == v: return

        if self.rank[u] < self.rank[v]:
            self.p[u] = v
            self.size[v] += self.size[u]
            self.size[u] = 0

            if self.mins[v] > self.mins[u]:
                self.mins[v] = self.mins[u]
                self.amins[v] = self.amins[u]
            self.mins[u] = -1
            self.mins[u] = -1
        else:
            self.p[v] = u
            self.size[u] += self.size[v]
            self.size[v] = 0

            if self.mins[u] > self.mins[v]:
                self.mins[u] = self.mins[v]
                self.amins[u] = self.amins[v]
            self.mins[v] = -1
            self.mins[v] = -1

            if self.rank[u] == self.rank[v]:
                self.rank[u] += 1

    def count(self, x):
        return self.size[self.root(x)]

    def min(self, x):
        return self.mins[self.root(x)]

uf = Uf(N, A.copy())

for _ in range(M):
    x, y = map(int, input().split())
    uf.unite(x, y)


mins = [x for x in uf.mins if x != -1]
amins = set([x for x in uf.amins if x != -1])
ans = sum(mins)
A = [a for i, a in enumerate(A) if i not in amins]
A.sort()
ntrees = len(mins)
if ntrees == 1:
    print(0)
    exit()
if ntrees * 2 - 2 > N:
    print("Impossible")
    exit()
ans += sum(A[:ntrees - 2])
print(ans)
