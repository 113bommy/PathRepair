import sys

def b(n):
    c = 0
    while n:
        if n & 1:
            c += 1
        n //= 2
    return c

c = {}

def f(n, k):
    if (n, k) in c.keys():
        return c[(n, k)]
    if n == 1:
        return 1 if k == 1 else 0
    c[(n, k)] = f(n // 2, k) + f(n // 2, k - 1) + int(n & 1 and b(n // 2) == k - 1)
    return c[(n, k)]

m, k = map(int, input().split())

hi = int(1e18)
lo = 1
while (hi - lo):
    mid = (lo + hi) // 2
    val = f(mid, k)
    if val == m:
        print(mid)
        sys.exit()
    elif val < m:
        lo = mid + 1
    else:
        hi = mid - 1