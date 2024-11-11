def main():
    import sys
    from collections import deque
    input = sys.stdin.readline

    # comb init
    mod = 1000000007
    nmax = 2*10 ** 5 + 10  # change here
    fac = [0] * nmax
    finv = [0] * nmax
    inv = [0] * nmax
    fac[0] = 1
    fac[1] = 1
    finv[0] = 1
    finv[1] = 1
    inv[1] = 1
    for i in range(2, nmax):
        fac[i] = fac[i - 1] * i % mod
        inv[i] = mod - inv[mod % i] * (mod // i) % mod
        finv[i] = finv[i - 1] * inv[i] % mod

    def comb(n, r):
        if n < r:
            return 0
        else:
            return (fac[n] * ((finv[r] * finv[n - r]) % mod)) % mod

    N = int(input())
    adj = [[] for _ in range(N+1)]
    for _ in range(N-1):
        a, b = map(int, input().split())
        adj[a].append(b)
        adj[b].append(a)


    que = deque()
    que.append(1)
    seen = [-1] * (N+1)
    seen[1] = 0
    par = [0] * (N+1)
    child = [[] for _ in range(N+1)]
    seq = []
    while que:
        v = que.popleft()
        seq.append(v)
        for u in adj[v]:
            if seen[u] == -1:
                seen[u] = seen[v] + 1
                par[u] = v
                child[v].append(u)
                que.append(u)
    seq.reverse()

    dp = [1] * (N+1)
    size = [1] * (N+1)
    for v in seq:
        for u in child[v]:
            size[v] += size[u]
        L = size[v] - 1
        for u in child[v]:
            dp[v] = (dp[v] * (dp[u] * comb(L, size[u]))%mod)%mod
            L -= size[u]

    seq.reverse()
    dp2 = [0] * (N+1)
    for v in seq:
        if v == 1:
            dp2[1] = dp[1]
            continue
        p = par[v]
        dp2[v] = dp[v]
        PP = (dp2[p] * pow((dp[v] * comb(N-1, size[v]))%mod, mod-2, mod))%mod
        dp2[v] = (dp2[v] * PP * comb(N-1, size[v]-1))%mod
    for v in range(1, N+1):
        print(dp2[v])


if __name__ == '__main__':
    main()
