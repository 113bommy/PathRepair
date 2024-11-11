n, k = map(int, input().split())
a = list(map(int, input().split()))
b = []
for i in range(1, n + 1):
    b.append(i)
for i in range(n):
    for j in range(n - i - 1):
        if a[j] > a[j + 1]:
            temp = a[j + 1]
            a[j + 1] = a[j]
            a[j] = temp
            temp = b[j + 1]
            b[j + 1] = b[j]
            b[j] = temp
p = 0
s = 0
for i in a:
    if s + i <= k:
        p += 1
        s += i
print(p)
for i in a[:p]:
    print(i, end=' ')