n = int(input())
for _ in range(n):
    x1, y1, x2, y2, x3, y3, x4, y4 = map(float, input().split())
    dx12, dx34, dy12, dy34 = x1 - x2, x3 - x4, y1 - y2, y3 - y4
    print('YES' if dx12 * dy34 - dy12 * dx34 < 1e-10 else 'NO')