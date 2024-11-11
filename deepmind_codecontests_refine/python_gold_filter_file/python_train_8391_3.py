n, m = map(int, input().split())
k = []
f = []
for _ in range(m):
    a, b = map(int, input().split())
    k.append(a)
    f.append(b)
mb = {i for i in range(1, 105)}
for i in range(m):
    now = set()
    for p in range(1, 105):
        if (k[i] - 1) // p + 1 == f[i]:
            now.add(p)
    mb.intersection_update(now)
can = set()
for x in mb:
    can.add((n - 1) // x + 1)
if len(can) != 1:
    print(-1)
else:
    for x in can:
        print(x)
