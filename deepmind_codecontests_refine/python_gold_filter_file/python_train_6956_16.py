# -*- coding: utf-8 -*-

import sys
from collections import Counter

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
INF = float('inf')
MOD = 10 ** 9 + 7

N = INT()
S = input()

S1 = list(S[:N])
# 左右同じものを目指す形にしたいので、片方はリバースしておく
S2 = list(S[N:])[::-1]

d1 = Counter()
d2 = Counter()
# 半分に分けた両方を組み合わせ全列挙
for i in range(1<<N):
    s1_1, s1_2 = [], []
    s2_1, s2_2 = [], []
    for j in range(N):
        if i>>j & 1:
            s1_1 += [S1[j]]
            s2_1 += [S2[j]]
        else:
            s1_2 += [S1[j]]
            s2_2 += [S2[j]]
    # 文字列ペアをキーとして、その通り数を数えておく
    d1[(''.join(s1_1), ''.join(s1_2))] += 1
    d2[(''.join(s2_1), ''.join(s2_2))] += 1

ans = 0
for k, v in d1.items():
    # 左文字列ペア = 右文字列ペア になるような通り数を数え上げる
    ans += v * d2[k]
print(ans)
