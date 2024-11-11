n = int(input())
a = list(map(int, input().split()))
d = list(map(lambda i: abs(a[i] - a[i + 1]), range(n - 1)))

x = list(map(lambda i: d[i] * (-1) ** i, range(0, n - 1)))
y = list(map(lambda i: d[i] * (-1) ** (i + 1), range(0, n - 1)))

max1 = x[0]
s = 0
for l in range(0, n - 2, 1):
    s += x[l]
    max1 = max([max1, s])
    s = max([s, 0])

max2 = max1
s = 0
for l in range(1, n - 2, 1):
    s += y[l]
    max2 = max([max2, s])
    s = max([s, 0])

print(max2)
