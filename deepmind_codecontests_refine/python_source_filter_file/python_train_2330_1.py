n, t = map(int,input().split())
a = list(map(int, input().split()))
l = 0
ans = 0
s = 0
for r in range(n):
    s += a[r]
    while s > t:
        l += 1
        s -= a[l - 1]
ans = max(ans, r - l + 1)
print(ans)
        