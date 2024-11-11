n, m = map(int, input().split())
print(n,m)
a = [[0] * n for l in range(m)]
for i in range(n):
    for j, k in enumerate(input()):
        a[j][i] = k
res = set()
for j in range(m):
    best = set()
    max_k = max(a[j])
    for i in range(n):
        if a[j][i] == max_k:
            best.add(i)
    res.update(best)
print(len(res))