x, y = [int(_) for _ in input().split()]
print(min(max(y - x, x - y + 2), abs(x + y) + 1))
