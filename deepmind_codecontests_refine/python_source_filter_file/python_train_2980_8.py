# 863C
import collections
def do():
    k, SA, SB = map(int, input().split(" "))
    a = {}
    b = {}
    for i in range(3):
        for j, c in enumerate(input().split(" ")):
            a[i+1, j+1] = int(c)
    for i in range(3):
        for j, c in enumerate(input().split(" ")):
            b[i+1, j+1] = int(c)

    seen = {}

    def put(sa, sb, cur, pa, pb):
        if sa == sb:
            seen[sa, sb] = (0, 0, cur)
        elif (sa, sb) == (1, 2):
            seen[sa, sb] = (0, 1, cur)
        elif (sa, sb) == (1, 3):
            seen[sa, sb] = (1, 0, cur)
        elif (sa, sb) == (2, 3):
            seen[sa, sb] = (0, 1, cur)
        elif (sa, sb) == (2, 1):
            seen[sa, sb] = (1, 0, cur)
        elif (sa, sb) == (3, 1):
            seen[sa, sb] = (0, 1, cur)
        elif (sa, sb) == (3, 2):
            seen[sa, sb] = (1, 0, cur)
        x, y, z = seen[sa, sb]
        seen[sa, sb] = (pa + x, pb + y, z)

    put(SA, SB, 1, 0, 0)
    sa, sb = SA, SB
    la, lb, _ = seen[sa, sb]
    p = 2
    while p < k:
        na, nb = a[sa, sb], b[sa, sb]
        # print([na, nb], seen)
        if (na, nb) in seen:
            x, y, z = seen[na, nb]
            put(na, nb, p, la, lb)
            nx, ny, nz = seen[na, nb]
            leng = nz - z
            mod = (k - z) % leng
            # print(["dasd", leng, mod])
            count = (k - z) // leng
            la, lb = (nx - x) * count + x, (ny - y) * count + y
            now = k - mod
            # print("now", now)
            sa, sb = na, nb
            while now < k:
                # print([na, nb], seen, la, lb)
                na, nb = a[sa, sb], b[sa, sb]
                put(na, nb, now, la, lb)
                now += 1
                la, lb, _ = seen[na, nb]
                sa, sb = na, nb
            return la, lb

        put(na, nb, p, la, lb)
        p += 1
        la, lb, _ = seen[na, nb]
        sa, sb = na, nb
    return la, lb

xx, yy = do()
print(str(xx) + " " + str(yy))

