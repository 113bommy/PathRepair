from math import ceil
n, m = map(int, input().split())
k = [0] * m
f = [0] * m
p = []
for i in range(m):
    k[i], f[i] = map(int, input().split())
for i in range(1, 101):
    good = True
    for j in range(m):
        if f[j] == ceil(k[j] / i):
            continue
        else:
            good = False
            break
    if good:
        p.append(i)
s = set()
for i in p:
    s.add(ceil(n / i))
if len(s) != 1:
    print(-1)
else:
    for i in s:
        print(i)

