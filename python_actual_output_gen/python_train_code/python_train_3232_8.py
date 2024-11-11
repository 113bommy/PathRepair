n, k, m = map(int, input().split())
a = sorted(list(map(int, input().split())))
ans = -2.0
s = sum(a)
for i in range(min(n, m)):
    ans = max(ans, ((min(m - i, (n - i) * k) + s) / (n - i)))
    s -= a[i]
print(ans)
