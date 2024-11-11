n, m, k, x, y = map(int, input().split())
if n > 1:
    t = 2 * (n - 1) * m
    s, p = k // t, k % t
    f = lambda x, y: s + s * (1 < x < n) + (p >= m * x - m + y) + (p >= (2 * n - x - 1) * m + y) * (x < n)
    print(max(f(1, 1), f(2, 1), f(n - 1, 1)), f(n, m), f(x, y))
else:
    g = lambda y: (k - y + m) // m
    print(g(1), g(m), g(y))