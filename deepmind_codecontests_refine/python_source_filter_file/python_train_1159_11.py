n = int(input())
a = [int(x) for x in input().split()]
c, b, j = sorted(a), [0] * n, 0
for i in range(0, n - 1, 2):
    b[j] = a[i]
    b[n - 1 - j] = a[i + 1]
    j += 1
if n % 2 == 1:
    b[n // 2] = a[n - 1]
print(b)
