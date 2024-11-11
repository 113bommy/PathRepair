import math

r, h = [int(r) for r in input().split(' ')]
print(math.floor((h / r * 2 + 1) + math.floor((h % r) / r + 0.2)))
print((h % r) / r)
