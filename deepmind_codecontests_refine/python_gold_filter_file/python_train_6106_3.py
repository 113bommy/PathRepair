def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, list(input())))

    # print(A, B)

    LMIN = -10**9
    LMAX = 10**9
    RMIN = -10**9
    RMAX = 10**9
    for i in range(4, n):
        if b[i-1] == 0 and b[i-2] == 0 and b[i-3] == 0 and b[i-4] == 0:
            if b[i] == 1:
                LMIN = max(LMIN, max(a[i],a[i-1],a[i-2],a[i-3],a[i-4])+1)
            elif b[i] == 0:
                LMAX = min(LMAX, max(a[i],a[i-1],a[i-2],a[i-3],a[i-4]))
        elif b[i-1] == 1 and b[i-2] == 1 and b[i-3] == 1 and b[i-4] == 1:
            if b[i] == 1:
                RMIN = max(RMIN, min(a[i],a[i-1],a[i-2],a[i-3],a[i-4]))
            elif b[i] == 0:
                RMAX = min(RMAX, min(a[i],a[i-1],a[i-2],a[i-3],a[i-4])-1)
        else:
            pass

    # print(LMIN, LMAX, RMIN, RMAX)

    # l = (LMIN + LMAX)//2

    print(LMIN, RMAX)

if __name__ == "__main__":
    solve()


