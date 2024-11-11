n, m, k, x, y = map(int, input().split())
if n == 1:
    t = m
elif m == 1:
    t = n + n - 2
else:
    t = n * m + (n - 2) * m

ma = -1
mi = 10 ** 30

a = [[0] * m for i in range(n)]
for i in range(n):
    for j in range(m):
        a[i][j] = k // t
        if i != 0 and i != n - 1:
            a[i][j] *= 2
k = k % t
print(a)
for i in range(n):
    for j in range(m):
        if k > 0:
            a[i][j] += 1
            k -= 1
            
for i in range(n - 2, -1, -1):
    for j in range(m):
        if k > 0:
            a[i][j] += 1
            k -= 1
            
for i in range(n):
    for j in range(m):
        ma = max(ma, a[i][j])
        mi = min(mi, a[i][j])
print(ma, mi, a[x - 1][y - 1])

