from math import ceil

n, k = map(int, input().split())
v = n
if v < k:
    print('NO')
else:
    r = []
    s = 0
    d = 0
    g = False
    while v != 0:
        if d + ceil(v / 2) <= k:
            x = v - k + d
            print('YES')
            g = True
            for i in range(x):
                print(2 ** (s + 1), end=' ')
            for i in range(v - 2 * x):
                print(2 ** s, end=' ')
            v = 0
            k = 0
        else:
            s += 1
            if v % 2 == 0:
                v //= 2
            else:
                r.append(2 * (s - 1))
                d += 1
                v -= 1
                v //= 2
    if not g:
        print('NO')
    else:
        print(*r)
