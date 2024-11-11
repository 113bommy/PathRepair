from itertools import accumulate
from math import ceil
N = int(input())
A = list(map(int, input().split()))


class BinaryIndexedTree:
    def __init__(self, n):
        self.size = n
        self.bit = [0] * (n + 1)

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.bit[i]
            i -= (i & -i)
        return s

    def add(self, i, x):
        while i <= self.size:
            self.bit[i] += x
            i += (i & -i)

    def reset(self):
        self.bit = [0] * (self.size + 1)


lo, hi = -1, 10 ** 9 + 1
BIT = BinaryIndexedTree(N + 1)
while hi - lo > 1:
    X = (hi + lo) // 2
    B = [(1 if a >= X else -1) for a in A]
    B = [0] + list(accumulate(B))
    B_sorted = {b: i for i, b in enumerate(sorted(B), start=1)}

    tmp = 0
    BIT.reset()
    for j, b in enumerate(B):
        tmp += BIT.sum(B_sorted[b])
        BIT.add(B_sorted[b], 1)

    if tmp >= ceil((N * (N + 1) / 2) / 2):
        lo = X
    else:
        hi = X

print(lo)
