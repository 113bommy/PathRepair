def f(l=0, r=int(10e5)):
    if r - l <= 1:
        return r
    mid = (l + r) // 2
    if mid * (mid - 1) // 2 >= m:
        return f(l, mid)
    else:
        return f(mid, r)

n, m = map(int, input().split())
print(n - m * 2 if m < n // 2 else 0, n - f() if m else n)