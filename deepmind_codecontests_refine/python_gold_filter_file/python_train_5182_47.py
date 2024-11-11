# 解説放送

def main():
    N, K = map(int, input().split())
    *P, = (int(x) - 1 for x in input().split())
    *C, = map(int, input().split())

    ans = -10**9 - 1

    for si in range(N):
        g = []
        tot = 0
        cur = si
        while True:
            cur = P[cur]
            g.append(C[cur])
            tot += C[cur]
            if cur == si or len(g) == K:
                break

        L = len(g)
        t = 0
        for i, x in enumerate(g, start=1):
            t += x
            now = t
            if tot > 0:
                rep = (K - i) // L
                now += tot * rep

            ans = max(ans, now)

    print(ans)


if __name__ == '__main__':
    main()
