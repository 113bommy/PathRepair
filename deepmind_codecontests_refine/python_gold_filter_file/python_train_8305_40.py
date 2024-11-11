import sys
from heapq import heappop, heappush
from operator import itemgetter
from collections import deque, defaultdict, Counter
from bisect import bisect_left, bisect_right
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)
MOD = 10**9 + 7
INF = float('inf')

class BIT:
    def __init__(self, size):
        self.size = size
        self.tree = [0] * (size + 1)

    def add(self, index):
        while index <= self.size:
            self.tree[index] += 1
            index += index & (-index)

    def sum(self, index):
        ret = 0
        while index:
            ret += self.tree[index]
            index -= index & (-index)
        return ret

    def search(self, value):
        i = 0
        s = 0
        step = 1 << (self.size.bit_length() - 1)
        while step:
            if i + step <= self.size and s + self.tree[i + step] < value:
                i += step
                s += self.tree[i]
            step //= 2
        return i + 1

def sol():
    N = int(input())
    P = [None] + list(map(int, input().split()))

    ans = 0
    pToIndex = {p : i for i, p in enumerate(P[1:], 1)}
    tree = BIT(N)

    for p in range(1, N + 1)[:: -1]:
        c = pToIndex[p]
        left = tree.sum(c)
        tree.add(c)

        right = N - p - left

        a = tree.search(left - 1) if left >= 2 else 0
        b = tree.search(left) if left >= 1 else 0
        d = tree.search(left + 2) if right >= 1 else N + 1
        e = tree.search(left + 3) if right >= 2 else N + 1

        cnt = 0
        if b != 0:
            cnt += (b - a) * (d - c)
        if d != 0:
            cnt += (e - d) * (c - b)

        ans += cnt * p

    print(ans)

sol()