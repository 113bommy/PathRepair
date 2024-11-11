u = int(input())
d = int(input())
a = [0 for i in range(u + d + 1)]
for i in range(u):
    a[i] = i
a[u] = d + u + 1
for i in range(u + 1, d + u + 1):
    a[i] = a[i - 1] - 1
print(*a)
