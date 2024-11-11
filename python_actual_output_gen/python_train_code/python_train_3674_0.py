from collections import defaultdict
from math import sqrt
def inpl(): return list(map(int, input().split()))
MOD = 10**9 + 7
N = int(input())
S = []

x = 0
for a in map(int, input().split()):
    x ^= a
    S.append(x)

A = defaultdict(int)
B = defaultdict(int)
L = defaultdict(int)
Z = 0

if S[-1] != 0:
    sr = S[-1]
    a, b = 0, 0
    for s in S:
        if s == sr:
            b =  (b + a + 1)%MOD
        elif s == 0:
            a = (a + b)%MOD
    print(b)
else:
    for s in S:
        if s == 0:
            Z += 1
        else:
            A[s] = (A[s] + (Z - L[s])*B[s])%MOD
            B[s] = (A[s] + B[s] + 1)%MOD
            L[s] = Z
    print((sum(B.values()) + pow(2, Z-1, MOD))%MOD)