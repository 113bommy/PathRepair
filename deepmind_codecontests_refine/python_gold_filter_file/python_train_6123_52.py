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

N = INT()
nodes = [[] for i in range(N)]
for i in range(N-1):
    a, b = MAP()
    a -= 1; b -= 1
    nodes[a].append(b)
    nodes[b].append(a)

# dp1[i] := 頂点iを白にしてその先の全体を塗り分ける通り数
dp1 = [1] * N
# dp2[i] := 頂点iを黒にしてその先の全体を塗り分ける通り数
dp2 = [1] * N
def rec(u, prev):
    for v in nodes[u]:
        if v != prev:
            rec(v, u)
            # 白 <= 白+黒 の遷移
            dp1[u] *= dp1[v] + dp2[v]
            dp1[u] %= MOD
            # 黒 <= 白 の遷移 
            dp2[u] *= dp1[v]
            dp2[u] %= MOD

rec(0, -1)
ans = (dp1[0]+dp2[0]) % MOD
print(ans)
