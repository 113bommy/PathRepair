n, m = map(int, input().split())
r = [(i ** 2) % m for i in range(1, m + 1)]
ost = [0] * m
for i in range(m):
    c = n // m
    if 0 < i <= n % m:
        c += 1
    ost[r[i]] += c
s = 0
for i in range(m):
    s += ost[i] * ost[(m - i) % m]
print(s)
