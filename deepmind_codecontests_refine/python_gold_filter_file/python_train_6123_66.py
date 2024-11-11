import sys
sys.setrecursionlimit(500000)

n = int(input())
mod = 10 ** 9 + 7
node = [[] for _ in range(n)]
memo_f, memo_g = [0] * n, [0] * n
for i in range(n - 1):
    x, y = map(int, input().split())
    node[x - 1].append(y - 1)
    node[y - 1].append(x - 1)

def f(x, prev):
    if memo_f[x]:
        return memo_f[x]
    memo_f[x] = 1
    for i in node[x]:
        if i == prev:
            continue
        memo_f[x] = (memo_f[x] * g(i, x)) % mod
    memo_f[x] = (memo_f[x] + g(x, prev)) % mod
    return memo_f[x]

def g(x, prev):
    if memo_g[x]:
        return memo_g[x]
    memo_g[x] = 1
    for i in node[x]:
        if i == prev:
            continue
        memo_g[x] = (memo_g[x] * f(i, x)) % mod
    return memo_g[x]

print(f(0, -1))