x1, y1, x2, y2 = [int(x) for x in input().split()]

print((y1 + y2) + (x2) + (y1 + y2 + abs(x1-x2) + (x1) + 4))
