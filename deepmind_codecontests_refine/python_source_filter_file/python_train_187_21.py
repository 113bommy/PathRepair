def main():
    N = int(input())
    F = [int(input().replace(' ', ''), 2) for _ in range(N)]
    P = [list(map(int, input().split())) for _ in range(N)]

    ans = -10 ** 7
    for i in range(1, 2 ** 10):
        c = 0
        for f, p in zip(F, P):
            c += p[bin(f & i).count('1')]
        ans = max(ans, c)
    print(ans)


main()
