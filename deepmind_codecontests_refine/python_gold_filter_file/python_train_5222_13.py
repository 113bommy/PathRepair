n, h, m = map(int,input().split())
a = n * [h]
for i in range(m):
    l, r, x = map(int,input().split())
    for j in range(l - 1, r):
        a[j] = min(a[j], x)

ans = 0
for i in a:
    ans += i**2
print(ans)
