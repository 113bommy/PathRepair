# -*- coding: utf-8 -*-

import sys

def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
def list4d(a, b, c, d, e): return [[[[e] * d for j in range(c)] for j in range(b)] for i in range(a)]
def ceil(x, y=1): return int(-(-x // y))
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def Yes(): print('Yes')
def No(): print('No')
def YES(): print('YES')
def NO(): print('NO')
sys.setrecursionlimit(10 ** 9)
INF = 10 ** 18
MOD = 10 ** 9 + 7

class BIT:
    """ BIT汎用版 """

    def __init__(self, n, func, init):
        # 0-indexed
        n += 1
        nv = 1
        while nv < n:
            nv *= 2
        self.size = nv
        self.func = func
        self.init = init
        self.tree = [init] * nv
    
    def query(self, i):
        """ [0, i]の値を取得 """
        s = self.init
        i += 1
        while i > 0:
            s = self.func(s, self.tree[i-1])
            i -= i & -i
        return s
    
    def update(self, i, x):
        """ 値の更新：添字i, 値x """
        i += 1
        while i <= self.size:
            self.tree[i-1] = self.func(self.tree[i-1], x)
            i += i & -i

N = INT()
H = LIST()
A = LIST()

bit = BIT(N+1, max, 0)
for h, a in zip(H, A):
    # ここより手前で出現した自分より低い花から、一番いいところを取る
    mx = bit.query(h)
    # 自身の最善の値を更新
    bit.update(h, mx + a)
ans = bit.query(N)
print(ans)
