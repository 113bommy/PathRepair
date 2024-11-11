from collections import defaultdict

class BIT(object):
    def __init__(self, N, init=0):
        self.N = N
        self.bit = [init for _ in range(N)]

    def add(self, k, w):
        x = k
        while x < self.N:
            self.bit[x] += w
            x |= x + 1

    def sum(self, k):
        s = 0
        x = k - 1
        while x >= 0:
            s += self.bit[x]
            x = (x & (x + 1)) - 1
        return s

n = int(input())
s = list(input())
q = int(input())

d = defaultdict(lambda: BIT(n))
for i, si in enumerate(s):
    d[si].add(i, 1)

for i in range(q):
    k, x, y = input().split()
    if k == '1':
        x = int(x) - 1
        d[s[x]].add(x, -1)
        d[y].add(x, 1)
        s[x] = y
    else:
        l = int(x) - 1
        r = int(y) - 1
        ans = 0
        for v in d.values():
            ans += (v.sum(r + 1) - v.sum(l)) > 0
        print(ans)
