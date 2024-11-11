n = int(input())
for i in range(n):
    x1, y1, x2, y2, x3, y3, x4, y4 = map(float, input().split())
    print('YES' if abs((x2 - x1)*(y4 - y3) - (x4 - x3)*(y2 - y1)) < 1e-10 else 'NO')