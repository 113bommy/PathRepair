def main():
    from sys import stdin
    input = stdin.readline

    n, m = map(int, input().split())
    s, t = map(lambda x: int(x)-1, input().split())
    g = [[] for _ in [0]*n]
    for i in range(m):
        a, b, c = map(int, input().split())
        g[a-1].append((b-1, c))
        g[b-1].append((a-1, c))

    import heapq
    inf = 10**16
    short = inf
    mod = 10**9+7

    dist_s = [inf]*n
    dp_s = ([0]*n)+[1]
    h = [(0, s, -1)]
    heapq.heapify(h)
    while h:
        d, i, a = heapq.heappop(h)
        if d > short:
            break
        elif i == t:
            short = d
        d2 = dist_s[i]
        if d2 == inf:
            dist_s[i] = d
            dp_s[i] = dp_s[a]
            for j, k in g[i]:
                if dist_s[j] == inf:
                    heapq.heappush(h, (d+k, j, i))
        elif d2 == d:
            dp_s[i] = (dp_s[i]+dp_s[a]) % mod

    dist_t = [inf]*n
    dp_t = ([0]*n)+[1]
    h = [(0, t, -1)]
    heapq.heapify(h)
    while h:
        d, i, a = heapq.heappop(h)
        if d > short:
            break
        d2 = dist_t[i]
        if d2 == inf:
            dist_t[i] = d
            dp_t[i] = dp_t[a]
            for j, k in g[i]:
                if dist_t[j] == inf:
                    heapq.heappush(h, (d+k, j, i))
        elif d2 == d:
            dp_t[i] = (dp_t[i]+dp_t[a]) % mod

    ans = dp_s[t]**2 % mod

    for i, (p, q) in enumerate(zip(dist_s, dist_t)):
        if p+q == short:
            d = p*2
            if d == short and q*2 == short:
                ans = (ans-(dp_s[i]*dp_t[i])**2) % mod
            elif d < short:
                for j, k in g[i]:
                    if d+2*k > short:
                        if d+2*k+2*dist_t[j] == 2*short:
                            ans = (ans-(dp_s[i]*dp_t[j])**2) % mod

    print(ans)


main()