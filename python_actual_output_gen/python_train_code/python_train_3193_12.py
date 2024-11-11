n = int(input())
a = list(map(int, input().split()))
a.sort()
l = 0
r = n - 1
x, y = 0, 0
while r - l >= 1:
    if l < r:
        x += a[r]
        y += a[l]
        l += 1
        r -= 1
    if l == r:
        x += a[r]
        r -= 1

print(x * x + y * y)
