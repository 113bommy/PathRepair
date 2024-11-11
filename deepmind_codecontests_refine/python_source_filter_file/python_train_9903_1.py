n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
d = {}
for i in range(n):
    if a[i] not in d:
        d[a[i]] = {b[i]}
    else:
        d[a[i]].add(b[i])
p = []
for dd in d:
    z = sorted(d[dd])
    for i in range(len(z) - 1):
        p.append(z[i])
p = sorted(p)
s = 0
for i in range(k - len(d)):
    s += p[i]
print(s)
