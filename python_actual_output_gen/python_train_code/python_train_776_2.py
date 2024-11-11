n, m = map(int, input().split())
a = map(int, input().split())

a = sorted(a)

res = a[m - 1]
for i in range(m - n):
    res = min(res, a[i + n - 1] - a[i])

print(res)
