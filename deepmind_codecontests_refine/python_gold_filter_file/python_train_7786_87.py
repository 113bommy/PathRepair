s = int(input())
x1 = 10 ** 9
y2 = s // x1
if s % x1 != 0:
    y2 += 1
y1 = y2 * x1 - s
print(0, 0, x1, y1, 1, y2)