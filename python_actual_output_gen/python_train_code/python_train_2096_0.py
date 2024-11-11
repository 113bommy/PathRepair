n, m = map(int, input().split())
s = 0
for i in range(n):
    t, T, x, c = map(int, input().split())
    k = T - t
    if k > 0:
        l = m // k
        if l == 0: s += c
        elif m == l * k == 0: s += min(c * l, c + x * m)
        else: s += min(c * (l + 1), c * l + x * (m - (l - 1) * k), c + x * m)
    else: s += c + x * m
print(s)