from collections import defaultdict
N, K, L = map(int, input().split())


class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n)]
        self.rank = [0] * n
        self.size = [1] * n

    # 検索
    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    # 併合
    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.rank[x] < self.rank[y]:
            self.par[x] = y
            self.size[y] += self.size[x]
            self.size[x] = 0
        else:
            self.par[y] = x
            self.size[x] += self.size[y]
            self.size[y] = 0
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    # 同じ集合に属するか判定
    def same_check(self, x, y):
        return self.find(x) == self.find(y)

    # すべての頂点に対して親を検索する
    def all_find(self):
        for n in range(1, len(self.par)):
            self.find(n)


UF1 = UnionFind(N)
UF2 = UnionFind(N)
for k in range(K):
    p, q = map(int, input().split())
    UF1.union(p-1, q-1)

for l in range(L):
    l, s = map(int, input().split())
    UF2.union(l-1, s-1)

UF1.all_find()
UF2.all_find()

D = defaultdict(int)
for i in range(N):
    D[UF1.par[i], UF2.par[i]] += 1

ans = [D[UF1.par[i], UF2.par[i]] for i in range(N)]
print(" ".join(map(str, ans)))
