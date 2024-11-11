x1, y1, r1 = map(int, input().split())
x2, y2, r2 = map(int, input().split())
d = ((x2 - x1) ** 2 + (y2 - y1) ** 2) ** .5
if d > r1 + r2:
    print(abs(r1 + r2 - d) / 2)
elif d < abs(r1 - r2):
    print(abs(r1 - r2) / 2)
else:
    print(0)
