a, b, n = map(int, input().split())
a = [0] * (n + 1)
a[0] = a
a[1] = b
for i in range(2, n):
    a[i] = a[i - 2] + a[i - 1]
print(a[n])