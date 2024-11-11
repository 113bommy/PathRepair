import sys
from operator import itemgetter


class BinaryIndexedTreeCustom:
    def __init__(self, n, init, func):
        self.size = n
        self.tree = [init] * (n + 1)
        self.depth = n.bit_length()
        self.init = init
        self.func = func

    def get(self, i):
        s = self.init
        while i > 0:
            s = self.func(s, self.tree[i])
            i -= i & -i
        return s

    def put(self, i, x):
        while i <= self.size:
            self.tree[i] = self.func(self.tree[i], x)
            i += i & -i


n, *aaa = map(int, sys.stdin.buffer.read().split())
bit1 = BinaryIndexedTreeCustom(n, 0, max)
bit2 = BinaryIndexedTreeCustom(n, n + 1, min)
aaa_with_index = list(enumerate(aaa, start=1))
aaa_with_index.sort(key=itemgetter(1))
ans = 0
for i, a in aaa_with_index:
    li = bit1.get(i)
    ri = bit2.get(n - i)
    ans += a * (i - li) * (ri - i)
    bit1.put(i, i)
    bit2.put(n + 1 - i, i)
print(ans)
