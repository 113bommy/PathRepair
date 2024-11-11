def main():
    mod = 10**9+7
    fact = [1, 1]
    for i in range(2, 200000):
        fact.append(fact[-1]*i % mod)
    n = int(input())
    ab = [list(map(int, input().split())) for _ in [0]*(n-1)]
    g = [[] for _ in [0]*n]
    [g[a-1].append(b-1) for a, b in ab]
    [g[b-1].append(a-1) for a, b in ab]
    g2 = [set(i) for i in g]
    child = [1]*n  # 子の数
    q = [-1, 0]
    while len(q) > 1:  # DFS
        i = q[-1]
        if g2[i]:
            j = g2[i].pop()
            g2[j].remove(i)
            q.append(j)
        else:
            q.pop()
            if len(q) > 1:
                child[q[-1]] += child[i]
    rank = [(j, i) for i, j in enumerate(child)]
    rank = [j for i, j in sorted(rank)]
    dp = [1]*n
    for i in rank:
        c = child[i]
        ans = fact[c-1]
        temp = 1
        for j in g[i]:
            if child[j] < c:
                ans = ans*dp[j] % mod
                temp = temp*fact[child[j]] % mod
        dp[i] = ans*pow(temp, mod-2, mod) % mod
    dp2 = [0]*n
    dp2[0] = dp[0]
    g2 = [set(i) for i in g]
    q = [-1, 0]
    while len(q) > 1:  # DFS
        i = q[-1]
        if g2[i]:
            j = g2[i].pop()
            c = child[j]
            temp = fact[n-c]*fact[c-1]
            dp2[j] = dp2[i]*(fact[c]*fact[n-c-1])*pow(temp, mod-2, mod) % mod
            g2[j].remove(i)
            q.append(j)
        else:
            q.pop()
            if len(q) > 1:
                child[q[-1]] += child[i]

    for i in dp2:
        print(i)


main()