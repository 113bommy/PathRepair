n, m = [int(z) for z in input().split()]
x, y = [int(z) for z in input().split()]
k = int(input())

res = 0
i = 0
while i < k:
    dx, dy = [int(z) for z in input().split()]
    if dx == 0:
        s = (m - y) // dy if dy > 0 else (1 - y) // dy
    elif dy == 0:
        s = (n - x) // dx if dx > 0 else (1 - x) // dx
    else:
        sx = (n - x) // dx if dx > 0 else (1 - x) // dx
        sy = (m - y) // dy if dy > 0 else (1 - y) // dy
        s = min(sx, sy)

    res += s
    x += s * dx
    y += s * dy
    i += 1
    print("dx = %d, dy = %d, s = %d, sx = %d, sy = %d, x = %d, y = %d" %
          (dx, dy, s, sx, sy, x, y))

print("%d" % res)
