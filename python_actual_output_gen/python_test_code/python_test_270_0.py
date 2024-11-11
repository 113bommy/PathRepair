m = int(input())

b = []
k = []
for i in range(m):
    x = int(input())
    c = 0
    for i in range(len(b)):
        v = b[i]
        d = k[i]
        if (x ^ v) < x:
            x ^= v
            c ^= d

    if x != 0:
        print(0)
        c ^= 2 ** i
        b.append(x)
        k.append(c)
    else:
        a = []
        for j in range(m):
            if c & 1 == 1:
                a.append(j)
            c >>= 1
        print(len(a), end='')
        for v in a:
            print(' ', v, sep='', end='')
        print()
