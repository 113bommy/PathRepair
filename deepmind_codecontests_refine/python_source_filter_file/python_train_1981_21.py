import math

x1, y1, x2, y2 = map(int, input().split())
print(math.sqrt(abs(x2-x1)**2 + abs(y2-y1)**2))
