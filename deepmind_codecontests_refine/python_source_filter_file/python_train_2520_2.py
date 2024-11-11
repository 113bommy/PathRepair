n, k = map(int, input().split())

coords = []
for _ in range(n):
    x, y = map(int, input().split())
    coords.append((x, y))

px, py = coords[0]
space = 0
for i in range(1, n):
    cx, cy = coords[i]
    dist = ((cx - px) * (cx - px) + (cy - py) * (cy - py)) ** 0.5
    space += dist
    px, py = cx, cy

ans = space / 5
print(ans)
