n, k = map(int, input().split())
h = n // 2 + n % 2
m = n - n // 2
if m == 0:
    print(0, 0, h)
else:
    a = h // (k + 1)
    print(h // (k + 1), a * k, n - (h // (k + 1) + a * k))
