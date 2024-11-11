import bisect


def solve(a, b, c):
    ans = 10**12
    for i in b:
        ind1 = bisect.bisect_right(a, i)
        ind2 = bisect.bisect_left(c, i)
        if ind1 == 0 or ind2 == len(c):
            continue
        j = a[ind1-1]
        k = c[ind2]
        ans = min(ans, (i-j)**2 + (j-k)**2 + (k-i)**2)

    return ans


for _ in range(int(input())):
    nr, ng, nb = map(int, input().split())
    r = sorted(list(map(int, input().split())))
    g = sorted(list(map(int, input().split())))
    b = sorted(list(map(int, input().split())))

    print(min(solve(r, g, b), solve(r, b, g), solve(b, r, g),
              solve(b, g, r), solve(g, r, b), solve(g, b, r)))
