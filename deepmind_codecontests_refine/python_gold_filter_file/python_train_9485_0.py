n, k = [int(i) for i in input().split()]
d = dict()
d[0] = 1
x = 0
for i in [int(i) for i in input().split()]:
    x ^= i
    v = min(x, (1 << k) - x - 1)
    if v not in d.keys():
        d[v] = 0
    d[v] += 1
ans = 0
for k, v in d.items():
    c1 = v // 2
    c2 = v - c1
    ans += c1 * (c1 - 1) // 2 + c2 * (c2 - 1) // 2
print(n * (n - 1) // 2 + n - ans)
