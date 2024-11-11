n, k = map(int, input().split())
f, t = [], []
for i in range(n):
    x, y = map(int, input().split())
    f.append(x)
    t.append(y)
t = [x for _, x in sorted(zip(f, t))]
f = sorted(f)
ans = -1
for i in range(n-1, -1, -1):
    val = 0
    if t[i] > k:
        val = f[i] - (t[i] - k)
    else:
        val = f[i]
    if val > ans:
        ans = val
print(ans)