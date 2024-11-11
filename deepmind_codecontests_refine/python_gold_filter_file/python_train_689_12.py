n, d = map(int, input().split())
a = list(map(int, input().split()))
ans = n - 1
a.sort()
for l in range(n):
    for r in range(l, n):
        if a[r] - a[l] <= d:
            ans = min(ans, l - 1 + (n - r))
print(ans)