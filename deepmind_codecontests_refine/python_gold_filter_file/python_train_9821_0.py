x, y, n = map(int, input().split())
a = [0] * (n + 1)
a[0] = x
a[1] = y
for i in range(2, n + 1):
    a[i] = a[i - 2] + a[i - 1]
print(a[n])
