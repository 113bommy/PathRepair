n, *a = map(int, open(0).read().split())
l, r = a[0], sum(a[1::])
ans = abs(l-r)
for i in range(1, n):
    l += a[i]
    r -= a[i]
    ans = min(ans, abs(l-r))
print(ans)