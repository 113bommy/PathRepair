n, *A = map(int, open(0).read().split())
ans, d = 0, {}
for i, a in enumerate(A, 1):
    x, y = i+a, i-a
    d[x] = d.get(x, 0)+1
    ans += d.get(y, 0)
print(ans)