import sys

def solve():
    input = lambda: sys.stdin.readline().rstrip()
    sys.setrecursionlimit(10 ** 7)
    mod = 10 ** 9 + 7

    def comb(n, r):
        if r > n: return 0
        return fac[n] * inv[r] * inv[n - r] % mod

    def dfs(v, Pa=-1):
        for u in to[v]:
            if u == Pa: continue
            dfs(u, v)
            size[v] += size[u]
            dp[v] *= dp[u] % mod
            dp[v] *= inv[size[u]] % mod
        dp[v] *= fac[size[v]] % mod
        size[v] += 1

    def bfs(v, Pa=-1, P_val=1, P_sz=0):
        ans[v] = P_val * dp[v] * comb(n - 1, P_sz) % mod
        for u in to[v]:
            if u == Pa: continue
            val = ans[v] * INV(dp[u] * comb(n - 1, size[u])) % mod
            bfs(u, v, val, n - size[u])

    n = int(input())
    to = [[] for _ in range(n)]
    for _ in range(n - 1):
        a, b = map(lambda x: int(x) - 1, input().split())
        to[a].append(b)
        to[b].append(a)

    fac = [1] * (n + 2)
    inv = [1] * (n + 2)

    for i in range(2, n + 1):
        fac[i] = fac[i - 1] * i % mod
    INV = lambda x: pow(x, mod - 2, mod)
    inv[n] = INV(fac[n])
    for i in range(n - 1, 1, -1):
        inv[i] = inv[i + 1] * (i + 1) % mod

    dp = [1] * n
    size = [0] * n
    ans = [0] * n

    dfs(0)
    bfs(0)
    print(*ans, sep='\n')

if __name__ == '__main__':
    solve()