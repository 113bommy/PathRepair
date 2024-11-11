from operator import itemgetter


class UnionFind:
    def __init__(self, n):
        self.table = [-1] * n

    def _root(self, x):
        if self.table[x] < 0:
            return x
        else:
            self.table[x] = self._root(self.table[x])
            return self.table[x]

    def find(self, x, y):
        return self._root(x) == self._root(y)

    def union(self, x, y):
        r1 = self._root(x)
        r2 = self._root(y)
        if r1 == r2:
            return
        d1 = self.table[r1]
        d2 = self.table[r2]
        if d1 <= d2:
            self.table[r2] = r1
            if d1 == d2:
                self.table[r1] -= 1
        else:
            self.table[r1] = r2


def solve(n, aaa, bbb):
    aai = sorted(enumerate(aaa), key=itemgetter(1))
    bbi = sorted(enumerate(bbb), key=itemgetter(1))
    uft = UnionFind(n)
    for (ai, a), (bi, b) in zip(aai, bbi):
        if a > b:
            return False
        uft.union(ai, bi)
    if sum(r < 0 for r in uft.table) > 1:
        return True
    return any(a >= b for (ai, a), (bi, b) in zip(aai[1:], bbi))


n = int(input())
aaa = list(map(int, input().split()))
bbb = list(map(int, input().split()))
print('Yes' if solve(n, aaa, bbb) else 'No')
