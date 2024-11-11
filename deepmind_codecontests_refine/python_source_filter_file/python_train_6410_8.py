n, m, k, x, y = map(int, input().split())

rw = [0] * n
pl = [[0] * m for r in range(n)]

def call():
    global k, rw, pl
    if n == 1:

        a, b = k // m, k % m;

        for i in range(m):
            pl[0][i] = a

        for i in range(b):
            pl[0][i] += 1

        return

    if k >= 30000:
        ite = 2 * m * (n-1)
        t = k // ite
        for i in range(n):
            rw[i] += 2 * t;

        rw[0] -= t
        rw[-1] -= t

        k -= t * ite


    act = 0
    up = 1
    while 1:
        if k > m:
            rw[act] += 1

            if up:
                act += 1
            else:
                act -= 1

            if act == n:
                act = n - 1
                up = 0

            if act == -1:
                act = 1
                up = 1

            k -= m

        else:
            for i in range(k):
                pl[act][i] += 1
            return

call()

for i in range(n):
    for j in range(m):
        pl[i][j] += rw[i]

mxges = max([max(pl[i]) for i in range(n)])
mnges = min([min(pl[i]) for i in range(n)])
gg = pl[x-1][y-1]

print("{} {} {}".format(mxges, mnges, gg))
