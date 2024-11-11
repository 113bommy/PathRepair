def solve():
    N = int(input())
    F = list(map(int, input().split()))
    G = []

    for i in range(N):
        G.append((F[i], i))

    G.sort()

    p = G[0][1]
    ans = 0

    for f, np in G:
        ans += abs(np - p)
        p = np

    print(ans)


if __name__ == '__main__':
    solve()
