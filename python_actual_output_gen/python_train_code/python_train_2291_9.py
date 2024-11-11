read = lambda: map(int, input().split())
x1, y1 = read()
x2, y2 = read()
print(min(abs(y1 - y2), abs(x1 - x2)))
