n, m, k = map(int, input().split())
 
if k <= n + m - 2:
    x = min(k + 1, n)
    y = k + 2 - x
    a = (n // x) * (m // y)
    y = min(k + 1, m)
    x = k + 2 - y
    b = (n // x) * (m // y)
    print(max(a, b))
else:
    print(-1)