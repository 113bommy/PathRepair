n = int(input())
ar = list(map(int, input().split()))
ar.sort()
x, y = 0, 0
for i in range((n + 1) // 2):
    if i * 2 == n - 1:
        y += ar[i]
    else:
        x += ar[i]
        y += ar[n - i - 1]
print(x * x + y * y)