n, k = map(int, input().split())
h = n // 2 + n % 2
m = n - h
if m == 0:
    print(0, 0, h)
else:
    a = m // (k + 1)
    print(m // (k + 1), a * k, n - (m // (k + 1) + a * k))
