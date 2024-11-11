# -*- coding: utf-8 -*-

import sys
from math import sqrt
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
sys.setrecursionlimit(10 ** 9)
INF = 10 ** 18
MOD = 10 ** 9 + 7

N, K = MAP()

M = int(sqrt(N))
i = 1
x = N
li1 = []
li2 = []
mul = []
while i < x:
    li1.append(x)
    i += 1
    prev = x
    x = N // i
    li2.append((prev - x) * (i - 1))
    mul.append(prev - x)
li = []
if i == x:
    li += li1 + [x] + li2[::-1]
else:
    li += li1 + li2[::-1]

M = len(li)
mul = [1] * (M-len(li2)) + mul[::-1]
dp = list2d(K-1, M, 0)
for i in range(M):
    dp[0][i] = li[i]

for i in range(1, K-1):
    acc = list(accumulate(dp[i-1]))[::-1]
    for j in range(M):
        dp[i][j] = acc[j] * mul[j] % MOD
print(sum(dp[K-2]) % MOD)
