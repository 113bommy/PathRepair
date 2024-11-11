n = int(input())
x, y = map(int, input().split())
if y > x: x, y = y, x
dist1 = y + (x - y) - 1
dist2 = (n - y) + (x - y) - 1
print('White' if dist1 <= dist2 else 'Black')