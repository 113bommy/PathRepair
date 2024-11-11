from operator import add, mul, sub, or_


class BIT:
    def __init__(self, n, op, ie):
        self.n = n
        self.tree = [ie]*(n+1)
        self.op = op

    def update(self, i, v):
        while i <= self.n:
            self.tree[i] = self.op(self.tree[i], v)
            i += i & (-i)

    def query(self, i):
        v = 0
        while i:
            v = self.op(self.tree[i], v)
            i -= i & (-i)
        return v


N, Q = map(int, input().split())
*c, = map(int, input().split())

q = [[] for _ in range(N+1)]
for i in range(Q):
    x, y = map(int, input().split())
    q[y-1].append([i, x-1])

bit = BIT(N, add, 0)
finds = [-1]*(N+1)
ans = [0]*Q
for i in range(N):
    if finds[c[i]] != -1:
        bit.update(finds[c[i]]+1, -1)

    finds[c[i]] = i
    bit.update(finds[c[i]]+1, 1)

    for j, x in q[i]:
        ans[j] = bit.query(i+1) - bit.query(x)

for a in ans:
    print(a)
