a, b, c = map(int, input().split())
x, y, z = map(int, input().split())
pos = 0
neg = 0
if (a > x):
    pos += (a - x) / 2
else:
    neg += x - a
if (b > y):
    pos += (b - y) / 2
else:
    neg += y - b
if (c > z):
    pos += (c - z) / 2
else:
    neg += z - c
if pos >= neg:
    print("Yes")
else:
    print("No")