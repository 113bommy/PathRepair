import sys

sys.setrecursionlimit(500005)
stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().strip()

class SegmentTreeOverwriteRMQ:
    M: int
    H: int
    N: int
    st: [int]
    cover: [int]
    I: int = 99999999999999

    def __init__(self, n):
        self.N = n
        self.H = 1
        while self.H < self.N:
            self.H *= 2
        self.M = self.H * 2
        self.cover = [self.I] * self.H
        self.st = [self.I] * self.M
        for i in range(self.H-1, 0, -1):
            self.propagate(i)

    def propagate(self, i):
        if self.cover[i] == self.I:
            self.st[i] = min(self.st[2*i], self.st[2*i+1])
        else:
            self.st[i] = self.cover[i]

    def update(self, l, r, v):
        self._update(l, r, v, 0, self.H, 1)

    def _update(self, l, r, v, cl, cr, cur):
        if l <= cl and cr <= r:
            if cr == cl + 1:
                self.st[cur] = v
            else:
                self.cover[cur] = v
                self.propagate(cur)
        else:
            mid = (cl+cr)//2
            bp = False
            if self.cover[cur] != self.I:
                if 2*cur >= self.H:
                    self.st[2*cur] = self.cover[cur]
                    self.st[2*cur+1] = self.cover[cur]
                else:
                    self.cover[2*cur] = self.cover[cur]
                    self.cover[2 * cur + 1] = self.cover[cur]
                    bp = True
                self.cover[cur] = self.I
            if cl < r and l < mid:
                self._update(l, r, v, cl, mid, 2*cur)
            elif bp:
                self.propagate(2*cur)
            if mid < r and l < cr:
                self._update(l, r, v, mid, cr, 2*cur+1)
            elif bp:
                self.propagate(2*cur+1)
            self.propagate(cur)

    def min(self, l, r):
        return self._min(l, r, 0, self.H, 1)

    def _min(self, l, r, cl, cr, cur):
        if l <= cl and cr <= r:
            return self.st[cur]
        else:
            if self.cover[cur] != self.I:
                return self.cover[cur]
            L, R = self.I, self.I
            mid = cl+cr>>1
            if cl < r and l < mid:
                L = self._min(l, r, cl, mid, 2*cur)
            if mid < r and l < cr:
                R = self._min(l, r, mid, cr, 2*cur+1)
            return min(L, R)

n, q = na()

row = SegmentTreeOverwriteRMQ(n+2)
row.update(2, n, n)

col = SegmentTreeOverwriteRMQ(n+2)
col.update(2, n, n)

rmin = n
cmin = n

black = (n-2)*(n-2)
for z in range(q):
    t, x = na()
    if t == 1:
        black -= row.min(x, x + 1) - 2
        if x < rmin:
            rmin = x
            col.update(0, cmin, rmin)
    else:
        black -= col.min(x, x + 1) - 2
        if x < cmin:
            cmin = x
            row.update(0, rmin, cmin)
print(black)

