import sys
input = sys.stdin.readline
from collections import deque

nn = 200200
mod = 10**9+7

fa = [1] * (nn+1)
fainv = [1] * (nn+1)
inv = [1] * (nn+1)
for i in range(nn):
    fa[i+1] = fa[i] * (i+1) % mod
fainv[-1] = pow(fa[-1], mod-2, mod)
for i in range(nn)[::-1]:
    fainv[i] = fainv[i+1] * (i+1) % mod
for i in range(1, nn)[::-1]:
    inv[i] = fainv[i] * fa[i-1]

C = lambda a, b: fa[a] * fainv[b] % mod * fainv[a-b] % mod if 0 <= b <= a else 0

N = int(input())
X = [[] for i in range(N)]
for i in range(N-1):
    x, y = map(int, input().split())
    X[x-1].append(y-1)
    X[y-1].append(x-1)

P = [-1] * N
Q = deque([0])
R = []
while Q:
    i = deque.popleft(Q)
    R.append(i)
    for a in X[i]:
        if a != P[i]:
            P[a] = i
            X[a].remove(i)
            deque.append(Q, a)

unit = 1
f = lambda a, b: a * b % mod
g_bu = lambda a, i=-1: a * inv[SI[i]] % mod
g_td = lambda a, i=-1: a * inv[N - SI[i]] % mod

SI = [1] * N
for i in R[::-1]:
    for j in X[i]:
        SI[i] += SI[j]

BU = [unit] * N
TD = [unit] * N
for i in R[::-1]:
    a = 1
    for j in X[i]:
        a = f(a, BU[j])
    BU[i] = g_bu(a, i)

AX = [1] * N
for i in R:
    c = len(X[i])
    ac = unit
    for k, j in enumerate(X[i]):
        AX[j] = ac
        ac = f(ac, BU[j])
    ac = unit
    for k in range(c-1, -1, -1):
        j = X[i][k]
        AX[j] = f(AX[j], ac)
        ac = f(ac, BU[j])
    for k, j in enumerate(X[i]):
        TD[j] = g_td(f(TD[i], AX[j]), j)

print(*[BU[i] * SI[i] % mod * TD[i] % mod * fa[N - 1] % mod for i in range(N)], sep = "\n")