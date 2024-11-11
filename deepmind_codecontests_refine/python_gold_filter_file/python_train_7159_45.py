import sys
from operator import itemgetter
buf = sys.stdin.buffer
input = buf.readline
class BIT:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * (n + 1)
    def add(self, i, x):
        n, tree = self.n, self.tree
        while i <= n:
            tree[i] += x
            i += i & -i
    def sum(self, i):
        tree = self.tree
        s = 0
        while i:
            s += tree[i]
            i -= i & -i
        return s
def main():
    n, q = map(int, input().split())
    res = [0] * q
    *c, = map(int, input().split())
    q = [(i, l, r) for i, (l, r) in enumerate(zip(*[map(int, buf.read().split())] * 2))]
    q.sort(key=itemgetter(2))
    bit = BIT(n + 2)
    add, sum = bit.add, bit.sum
    b = [1] * (n + 1)
    j = 1
    for i, l, r in q:
        while j <= r:
            d = c[j - 1]
            j += 1
            k = b[d]
            b[d] = j
            add(k + 1, 1)
            add(j + 1, -1)
        res[i] = sum(l + 1)
    print(' '.join(map(str, res)))
main()