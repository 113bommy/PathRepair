import sys

k, l, r, t, x, y = tuple(map(int, input().split()))

if x == y:
    if k + y <= r or k - x >= l:
        print('Yes')
    else:
        print('No')
elif y < x:
    if k + y <= r:
        k += y
    if k - t * x + (t - 1) * y >= l:
        print('Yes')
    else:
        print('No')
else:
    k -= l
    r -= l
    l = 0

    first = k // x
    k %= x
    t -= first

    ost = {k}
    while t > 0:
        if k + y > r:
            print('No')
            sys.exit()

        now = (k + y) // x
        k = (k + y) % x
        t -= now

        if k in ost:
            break
        ost.add(k)

    print('Yes')
