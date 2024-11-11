k, l, m, n, d = [int(input()) for _ in range(5)]
a = [0] * (d + 1)
for i in range(1, d + 1, k):
    a[i] = 1
for i in range(1, d + 1, l):
    a[i] = 1
for i in range(1, d + 1, m):
    a[i] = 1
for i in range(1, d + 1, n):
    a[i] = 1
print(sum(a))