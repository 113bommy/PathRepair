class fenwick_tree:
    def __init__(self, n):
        self.data = [0 for _ in range(n+1)]
        self.n = n

    def add(self, p, x):
        p += 1
        while p <= self.n:
            self.data[p-1] += x
            p += p & -p
    
    def sum(self, l, r):
        return self._sum(r) - self._sum(l)

    def _sum(self, r):
        s = 0
        while r > 0:
            s += self.data[r-1]
            r -= r & -r
        return s
    
N, Q = [int(_) for _ in input().split()]

fw = fenwick_tree(N)
A = [int(_) for _ in input().split()]
for i, a in enumerate(A):
    fw.add(i, a)

for i in range(Q):
    t, *q = [int(_) for _ in input().split()]
    if t == 0:
        p, x = q
        fw.add(p, x)
    else:
        l, r = q
        print(fw.sum(l, r))
