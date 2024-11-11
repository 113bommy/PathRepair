import sys

sys.setrecursionlimit(5001)
MOD = 10 ** 9 + 7

n = int(input())
links = [set() for _ in range(n)]
for line in sys.stdin.readlines():
    x, y = map(int, line.split())
    x -= 1
    y -= 1
    links[x].add(y)
    links[y].add(x)

double_factorial_odd = [0] * (n // 2)
prev = 1
for i in range(n // 2):
    prev = double_factorial_odd[i] = (2 * i + 1) * prev % MOD


def dfs(v, p):
    ret = [0, 1]
    for u in links[v]:
        if u == p:
            continue
        res = dfs(u, v)
        lt, ls = len(ret), len(res)
        mrg = [0] * (lt + ls - 1)
        for i in range(1 - lt % 2, lt, 2):
            c = ret[i]
            for j in range(1 - ls % 2, ls, 2):
                mrg[i + j] = (mrg[i + j] + c * res[j]) % MOD
        ret = mrg

    if len(ret) % 2 == 1:
        ret[0] = -sum(pattern * df % MOD for pattern, df in zip(ret[2::2], double_factorial_odd)) % MOD

    return ret


print(MOD - dfs(0, -1)[0])
