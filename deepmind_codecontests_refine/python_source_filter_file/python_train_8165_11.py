n = int(input())
a = list(map(int, input().split()))
d = {}
for i in range(n):
    d[a[i]] = d.get(a[i], 0) + a[i]

b = [0] * (10 ** 5 + 5)
b[1] = d.get(1, 0)
res = 0
for i in range(2, 10 ** 5 + 5):
    b[i] = max(b[i], b[i-2] + d.get(i, 0))
    res = max(res, b[i])

print(res)