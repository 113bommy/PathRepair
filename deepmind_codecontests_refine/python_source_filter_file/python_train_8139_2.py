# unionfind
class Uf:
    def __init__(self, N):
        self.p = list(range(N))
        self.rank = [0] * N
        self.size = [1] * N

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
        else:
            self.p[v] = u
            self.size[u] += self.size[v]
            self.size[v] = 0

            if self.rank[u] == self.rank[v]:
                self.rank[u] += 1

    def count(self, x):
        return self.size[self.root(x)]

import sys
from operator import itemgetter
def main():
    input = sys.stdin.readline
    N, M = map(int, input().split())
    # harmonious <=> l < m < r で、l から r に辿り着けるなら、l から m に辿り着ける

    uf = Uf(N+1)
    for u, v in zip(*[iter(map(int, sys.stdin.read().split()))]*2):
        uf.unite(u, v)

    L = [10**9] * (N+1)
    R = [-1] * (N+1)
    for i in range(1, N+1):
        r = uf.root(i)
        L[r] = min(L[r], i)
        R[r] = max(R[r], i)
    ans = 0
    LR = []
    for l, r in zip(L, R):
        if r != -1:
            LR.append((l, r))
    LR.sort(key=itemgetter(0))
    rr = -1
    for l, r in LR:
        if rr > l:
            ans += 1
        rr = r
    print(ans)


main()
