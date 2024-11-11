n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a1 = [0] * n
b1 = [0] * n
a1[0] = a[0]
b1[0] = b[0]
if n > 1:
    a1[1] = b[0] + a[1]
    b1[1] = a[0] + b[1]

for i in range(2, n):
    a1[i] = max(b1[i - 1] + a[i], b1[i - 2] + a[i], a1[i - 1])
    b1[i] = max(a1[i - 1] + b[i], a1[i - 2] + a[i], b1[i - 1])

print(max(a1[n - 1], b1[n - 1]))
