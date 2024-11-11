# -*- coding: utf-8 -*-

import sys
from itertools import accumulate

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
INF = 10 ** 18
MOD = 10 ** 9 + 7

N, K, S = MAP()

if S / K > N - 1 or K > S:
    NO()
    exit()

d, m = divmod(S, K)
move = [d] * K
for i in range(m):
    move[i] += 1
cur = 1
ans = []
for i in range(K):
    if i % 2 == 0:
        cur += move[i]
    else:
        cur -= move[i]
    ans.append(cur)
YES()
print(*ans)
