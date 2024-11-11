import sys
sys.setrecursionlimit(10 ** 7)

MOD = 10**9 + 7

def MOD_inv(a):
    b = MOD
    u = 1
    v = 0
    while b > 0:
        t = a // b
        a -= t * b
        a, b = b, a
        u -= t * v
        u, v = v, u
    u = u % MOD
    if u < 0:
        u += MOD
    return u

def init_Graph(G):
    for _ in range(len(G)-1):
        a, b = map(int, input().split())
        a, b = a-1, b-1
        G[a].append(b)
        G[b].append(a)

def dfs(G, dp, t, perm, crr, pre):
    tmp = 1
    f = False
    for nxt in G[crr]:
        if nxt == pre:
            continue
        dfs(G, dp, t, perm, nxt, crr)
        t[crr] += t[nxt]
        tmp *= dp[nxt]
        f = True
    if f:
        dp[crr] = perm[t[crr]-1]
        for nxt in G[crr]:
            if nxt == pre:
                continue
            dp[crr] *= MOD_inv(perm[t[nxt]]) * dp[nxt]
            dp[crr] %= MOD
    else:
        dp[crr] = 1

def solve(G, dp, t, perm, crr, pre, mul):
    dp[crr] *= MOD_inv(perm[t[crr]-1]) * perm[len(G)-1] * mul
    dp[crr] %= MOD
    for nxt in G[crr]:
        if nxt == pre:
            continue
        crr_t = len(G)
        crr_t -= t[nxt]
        crr_dp = dp[crr]
        crr_dp *= perm[t[nxt]] * MOD_inv(perm[len(G)-1]) * perm[len(G)-t[nxt]-1] * MOD_inv(dp[nxt])
        crr_dp %= MOD
        tmp = MOD_inv(perm[crr_t]) * crr_dp % MOD
        solve(G, dp, t, perm, nxt, crr, tmp)

def main():
    n = int(input())
    G = [[] for _ in range(n)]
    init_Graph(G)
    t = [1]*n
    dp = [0]*n
    perm = [1]*(2 * 10**5 + 10)
    for i in range(2, 2 * 10**5 + 10):
        perm[i] = perm[i-1] * i % MOD
    dfs(G, dp, t, perm, 0, -1)
    solve(G, dp, t, perm, 0, -1, 1)
    for v in dp:
        print(v)

if __name__ == "__main__":
    main()