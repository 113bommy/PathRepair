#線分交差問題

import bisect

class BIT:
    def __init__(self, n):
        self.tree = [0]*(n+1)
        self.n = n
    
    def add(self, i, v):
        while i <= self.n:
            self.tree[i] += v
            i += i & -i
        
    
    def _sum(self, i):
        ret = 0
        while i:
            ret += self.tree[i]
            i -= i & -i
        return ret
    
    def sum(self, l, h):
        return self._sum(h) - self._sum(l-1)
    
n = int(input())
vx = []
xs = set()
for _ in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    if x1 == x2:
        if y1 > y2:
            y1, y2 = y2, y1
        vx.append((y1, float('-inf'),x1))
        vx.append((y2, float('inf'),x2))
        xs.add(x1)
    else:
        if x1 > x2:
            x1, x2 = x2, x1
        vx.append((y1, x1, x2))
vx.sort()

bit = BIT(len(xs))
xs = [float('-inf')] + sorted(xs)
ix = {v: i for i, v in enumerate(xs)}
ans = 0

for y, j, x2 in vx:
    if j == float('-inf'):
        bit.add(ix[x2],1)
    elif j == float('inf'):
        bit.add(xs.index(x2), -1)
    else:
        l = bisect.bisect_left(xs, j)
        r = bisect.bisect(xs, x2) - 1
        ans += bit.sum(l, r)
        
print(ans)

