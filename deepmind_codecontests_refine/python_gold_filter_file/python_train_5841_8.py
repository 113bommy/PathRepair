n = int(input())
ax, ay = map(int, input().split())
bx, by = map(int, input().split())
cx, cy = map(int, input().split())
dx, dy = bx - ax, by - ay
ex, ey = cx - ax, cy - ay
if dx / abs(dx) == ex / abs(ex) and dy / abs(dy) == ey / abs(ey):
    print("YES")
else:
    print("NO")
