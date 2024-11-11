import sys
import io, os
input = sys.stdin.buffer.readline

n,q = map(int, input().split())
parent = list(map(int, input().split()))
UK = []
for i in range(q):
    u,k = map(int, input().split())
    u,k = u-1, k-1
    UK.append((u, k))


parent = [p-1 for p in parent]
parent = [-1]+parent

g = [[] for _ in range(n)]
for i, p in enumerate(parent):
    if p == -1:
        continue
    else:
        g[p].append(i)

g = [list(reversed(l)) for l in g]

#print(g)

root = 0
s = [root]
order = []
left = [0]*n
right = [-1]*n
depth = [-1]*n

num = -1
de = -1

while s:
    q = s.pop()
    if q >= 0:
        num += 1
        order.append(q)
        left[q] = num
        right[q] = num
        s.append(~q)
        de += 1
        depth[q] = de
        for v in g[q]:
            s.append(v)
    else:
        de -= 1
        if ~q != root:
            order.append(parent[~q])
            num += 1
            right[parent[~q]]  = num

#print(left)
#print(right)
print(order)
print(left)
print(right)

class BIT:
    def __init__(self, n):
        self.n = n
        self.bit = [0]*(self.n+1) # 1-indexed

    def init(self, init_val):
        for i, v in enumerate(init_val):
            self.add(i, v)

    def add(self, i, x):
        # i: 0-indexed
        i += 1 # to 1-indexed
        while i <= self.n:
            self.bit[i] += x
            i += (i & -i)

    def sum(self, i, j):
        # return sum of [i, j)
        # i, j: 0-indexed
        return self._sum(j) - self._sum(i)

    def _sum(self, i):
        # return sum of [0, i)
        # i: 0-indexed
        res = 0
        while i > 0:
            res += self.bit[i]
            i -= i & (-i)
        return res

    def lower_bound(self, x):
        s = 0
        pos = 0
        depth = self.n.bit_length()
        v = 1 << depth
        for i in range(depth, -1, -1):
            k = pos + v
            if k <= self.n and s + self.bit[k] < x:
                    s += self.bit[k]
                    pos += v
            v >>= 1
        return pos

bit = BIT(len(order)+1)
for l in left:
    bit.add(l, 1)

for u, k in UK:
    l = left[u]
    r = right[u]
    t = bit.sum(l, r+1)
    if t < k+1:
        print(-1)
    else:
        p = bit.sum(0, l)
        x = bit.lower_bound(p+k+1)
        print(order[x]+1)
