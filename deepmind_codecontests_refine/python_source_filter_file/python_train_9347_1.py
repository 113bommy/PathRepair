n, *a = map(int, open(0).read().split())
l, r = a[0], sum(a[1::])
ans = 1e20
for i in range(1, n):
    l += a[i]
    r -= a[i]
    ans = min(ans, abs(l-r))
print(ans)