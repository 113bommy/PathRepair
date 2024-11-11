import sys
from bisect import bisect_left
from operator import itemgetter


class SegTreeMax:
    """
    以下のクエリを処理する
    1.update:  i番目の値をxに更新する
    2.get_min: 区間[l, r)の最小値を得る
    """

    def __init__(self, n, INF):
        """
        :param n: 要素数
        :param INF: 初期値（入りうる要素より十分に大きな数）
        """
        n2 = 1 << (n - 1).bit_length()
        self.offset = n2
        self.tree = [INF] * (n2 << 1)
        self.INF = INF

    def initialize(self, arr):
        for i, v in enumerate(arr, start=self.offset):
            self.tree[i] = v
        for i in range(self.offset - 1, 0, -1):
            j = i << 1
            self.tree[i] = max(self.tree[j], self.tree[j + 1])

    def update(self, i, x):
        """
        i番目の値をxに更新
        :param i: index(0-indexed)
        :param x: update value
        """
        i += self.offset
        self.tree[i] = x
        while i > 1:
            y = self.tree[i ^ 1]
            if y >= x:
                break
            i >>= 1
            self.tree[i] = x

    def get_max(self, a, b):
        """
        [a, b)の最大値を得る
        :param a: index(0-indexed)
        :param b: index(0-indexed)
        """
        result = self.INF

        l = a + self.offset
        r = b + self.offset
        while l < r:
            if r & 1:
                result = max(result, self.tree[r - 1])
            if l & 1:
                result = max(result, self.tree[l])
                l += 1
            l >>= 1
            r >>= 1

        return result


n, *xd = map(int, sys.stdin.buffer.read().split())
MOD = 998244353
xd = sorted(zip(xd[0::2], xd[1::2]))
xxx = list(map(itemgetter(0), xd))
ans = [0] * (n + 1)
skip = list(range(1, n + 1))
ans[n] = 1
sgt = SegTreeMax(n + 1, 0)
sgt.initialize(list(range(1, n + 2)))
for i in range(n - 1, -1, -1):
    x, d = xd[i]
    r = x + d
    j = bisect_left(xxx, r)
    k = sgt.get_max(i, j)
    ans[i] = (ans[i + 1] + ans[k]) % MOD
    sgt.update(i, k)
print(ans[0])
