import math
import os
import sys

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(2147483647)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7


class SparseTable:
    """
    構築 O(NlogN)、クエリ O(1)
    """

    def __init__(self, values, fn):
        """
        :param list values:
        :param callable fn: 結合則を満たす冪等な関数。min、max など。add はだめ
        """
        self._values = values
        self._fn = fn

        # SparseTable を構築
        # self._table[i][p]: [i, i+2^p) に fn を適用した結果の値のインデックス
        self._table = self._build(values, fn)

        # self._msb[i]: 最上位ビット; どの p を見るべきか
        self._msb = [0] * (len(values) + 1)
        for i in range(2, len(values) + 1):
            self._msb[i] = self._msb[i >> 1] + 1

    @staticmethod
    def _build(values, fn):
        # AtCoder の PyPy 2.4.0 では math.log2 が使えない
        size = int(math.log(len(values), 2)) + 1

        st = [[0] * size for _ in range(len(values))]
        for i in range(len(values)):
            st[i][0] = i
        for p in range(1, size):
            for i in range(len(values)):
                q = min(i + (1 << (p - 1)), len(values) - 1)
                l = st[i][p - 1]
                r = st[q][p - 1]
                if values[l] == fn(values[l], values[r]):
                    st[i][p] = l
                else:
                    st[i][p] = r
        return st

    def get(self, a, b):
        """
        半開区間 [a, b) に fn を適用した結果
        :param int a:
        :param int b:
        """
        if b <= a:
            return None
        p = self._msb[b - a]
        return self._fn(
            self._values[self._table[a][p]],
            self._values[self._table[b - (1 << p)][p]]
        )


N, K = list(map(int, sys.stdin.readline().split()))
P = list(map(int, sys.stdin.readline().split()))

dp = [1] * N
for i in range(1, N):
    if P[i - 1] < P[i]:
        dp[i] = dp[i - 1] + 1

# 全部昇順じゃない場合の答え
ans = N - K + 1

asc_cnt = 0
st_max = SparseTable(P, max)
st_min = SparseTable(P, min)
for r in range(K, N):
    l = r - K
    if st_min.get(l, r) == P[l] and st_max.get(l + 1, r + 1) == P[r]:
        # 出ていったのが最小値で、入ってきたのが最大値のとき、変わらない
        ans -= 1
    elif dp[r] >= K:
        # すでに昇順
        ans -= 1
        asc_cnt += 1
if dp[K - 1] >= K:
    # すでに昇順
    ans -= 1
    asc_cnt += 1

if asc_cnt > 0:
    # すでに昇順のやつは一度だけ数えていい
    ans += 1
print(ans)
