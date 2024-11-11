a, b = sorted(map(int, input().split()))
res = 0
while a > 2 or b > 2:
    x, y = divmod(b, 2)
    if y == 0:
        x -= 1
        y = 2
    a += x
    res += x
    b = y
    a, b = sorted([a, b])
if a == 2 and b == 2:
    res += 1
print(res)