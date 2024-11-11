x, y = [int(i) for i in input().split()]
print(min(max(y - x, x - y + 2), abs(x + y) + 1))