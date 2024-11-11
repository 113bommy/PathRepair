def solve(n, R, P):
    r, p = 0, 0
    for i in range(n):
        if R[i] == 1 and P[i] == 0:
            r += 1
        if R[i] == 0 and P[i] == 1:
            p += 1
    if r == 0:
        print(-1)
        return
    p += 1
    ans = p // r + p % r
    print(ans)


def main():
    inp = lambda: [int(x) for x in input().split()]
    n = int(input())
    R = inp()
    P = inp()
    solve(n, R, P)


if __name__ == "__main__":
    main()

