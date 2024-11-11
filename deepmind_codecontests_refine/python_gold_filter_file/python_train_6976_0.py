n, a = int(input()), input().split()
ta = list((int(c[1]), i, c) for i, c in enumerate(a))
ca = sorted(ta)

ba = ta[:]
for i in range(n):
    for j in range(n - 1, i, -1):
        if ba[j][0] < ba[j - 1][0]:
            ba[j], ba[j - 1] = ba[j - 1], ba[j]

print(*[t[2] for t in ba])
print(('Not s' if ba != ca else 'S') + 'table')

sa = ta[:]
for i in range(n):
    minj = i
    for j in range(i, n):
        if sa[j][0] < sa[minj][0]:
            minj = j
    if minj != i:
        sa[i], sa[minj] = sa[minj], sa[i]

print(*[t[2] for t in sa])
print(('Not s' if sa != ca else 'S') + 'table')