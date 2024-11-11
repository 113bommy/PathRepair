from sys import stdin,stderr
def rl():
    return [int(w) for w in stdin.readline().split()]

t, = rl()
for _ in range(t):
    n, = rl()
    a = rl()
    m = a[n-1]
    d = 0
    for i in range(n-2,-1,-1):
        if a[i] < m:
            m = a[i]
        elif a[i] > m + d:
            d = a[i] - m
    r = 0
    r2 = 1
    while r2 < 2*d:
        r += 1
        r2 *= 2
    print(r)
