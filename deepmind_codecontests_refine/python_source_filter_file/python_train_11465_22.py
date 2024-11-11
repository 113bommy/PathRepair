n = int(input())
eps = float(0.0000001)

for i in range(n):
    x = float(input())

    l = 0.0
    r = x
    f = 0
    it = 0
    a = b = 0.0

    while it < 2000:
        it += 1
        mid = (l + r) / 2
        b = mid
        a = x - b

        if abs((a + b) - a * b) <= eps:
            f = 1
            break

        if a + b <= a * b:
            r = mid
        else:
            l = mid

    if f == 0:
        print('NO')
    else:
        print('Y', a, b)
