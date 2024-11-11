n, m, p = [int(i) for i in input().split()]
e = [[int(i) for i in input().split()] for _ in range(m)]

for i in e:
    i[0] -= 1
    i[1] -= 1
    i[2] -= p

d = [-10**18] * n
ok1 = [False] * n
ok2 = [False] * n
d[0] = 0
ok1[0] = True
ok2[-1] = True

for _ in range(n):
    for a, b, c in e:
        if ok1[a]:
            d[b] = max(d[b], d[a] + c)
            ok1[b] = True
        if ok2[b]:
            ok2[a] = True
aa = d[:]

for _ in range(1):
    for a, b, c in e:
        if ok1[a]:
            d[b] = max(d[b], d[a] + c)
            ok1[b] = True
        if ok2[b]:
            ok2[a] = True

bb = d[:]

ok = False
for i in range(n):
    if ok1[i] and ok2[i]:
        if aa[i] != bb[i]:
            ok = True
if ok:
    print("-1")
else:
    print(max(aa[-1], 0))
