n = int(input())
ax, ay = map(int, input().split())
bx, by = map(int, input().split())
cx, cy = map(int, input().split())
dx, dy = ax - bx, ay - by
ex, ey = ax - cx, ax - cy
if dx / abs(dx) == ex / abs(ex) and dy / abs(dy) == ey / abs(ey):
    print("YES")
else:
    print("NO")
