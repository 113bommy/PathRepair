def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    inf = 2 * 10**9
    L = [inf, inf, inf]
    R = [-inf, -inf, -inf]
    U = [-inf, -inf, -inf]
    D = [inf, inf, inf]
    for _ in range(N):
        x, y, d = input().split()
        x = int(x) * 2
        y = int(y) * 2
        if d == 'L':
            L[0] = min(L[0], x)
            R[1] = max(R[1], x)
            U[2] = max(U[2], y)
            D[2] = min(D[2], y)
        elif d == 'R':
            L[1] = min(L[1], x)
            R[0] = max(R[0], x)
            U[2] = max(U[2], y)
            D[2] = min(D[2], y)
        elif d == 'U':
            L[2] = min(L[2], x)
            R[2] = max(R[2], x)
            U[0] = max(U[0], y)
            D[1] = min(D[1], y)
        else:
            L[2] = min(L[2], x)
            R[2] = max(R[2], x)
            U[1] = max(U[1], y)
            D[0] = min(D[0], y)

    def calc(t):
        if t < 0:
            return 10**20
        xmin = min(L[0] - t, L[1] + t, L[2])
        xmax = max(R[0] + t, R[1] - t, R[2])
        ymax = max(U[0] + t, U[1] - t, U[2])
        ymin = min(D[0] - t, D[1] + t, D[2])
        return (xmax - xmin) * (ymax - ymin)

    ans = calc(0)
    ans = min(ans, calc((L[0] - L[1]) // 2), calc(L[0] - L[2]), calc(L[2] - L[1]))
    ans = min(ans, calc((R[1] - R[0]) // 2), calc(R[2] - R[0]), calc(R[2] - R[1]))
    ans = min(ans, calc((U[1] - U[0]) // 2), calc(U[2] - U[0]), calc(U[2] - U[1]))
    ans = min(ans, calc((D[0] - D[1]) // 2), calc(D[0] - D[2]), calc(D[2] - D[1]))
    print(ans / 4)


if __name__ == '__main__':
    main()
