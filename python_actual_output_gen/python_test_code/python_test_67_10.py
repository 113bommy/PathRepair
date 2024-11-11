n = int(input())
a = list(map(int, input().split()))
b = []
for i in range(n - 1):
    b.append(a[i] - a[i + 1])
mx = -float('inf')
now = 0
for i in range(n - 1):
    now += b[i] * (-1) ** (i % 2)
    mx = max(mx, now)
    if now < 0:
        now = 0
now = 0
for i in range(1, n - 1):
    now += b[i] * (-1) ** (i % 2 + 1)
    mx = max(mx, now)
    if now < 0:
        now = 0
print(mx)
