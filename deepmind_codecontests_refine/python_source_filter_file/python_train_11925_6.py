def sev(n):
    if n == 0:
        return 1
    m = 0
    while n > 0:
        n //= 7
        m += 1
    return m

def fil(n, m, l, r):
    d = []
    for i in range(l):
        d += [m % 7]
        m //= 7
    for i in range(l):
        d += [n % 7]
        n //= 7
    
    if len(set(d)) != l + r:
        return 0
    return 1

n, m = map(int, input().split())
l, r = sev(n), sev(m)

if l + r > 7:
    print(0)
else:
    c = 0
    for i in range(n):
        for j in range(m):
            c += fil(i, j, l, r)
    print(c)
