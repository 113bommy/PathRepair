import math


def calculate_distance(x1, y1, x2, y2):
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)


a = []
x1, y1, x2, y2 = list(map(int, input().split()))
if x2 < x2:
    x1, x2 = x2, x1
if y2 < y1:
    y1, y2 = y2, y1
for i in range(x1, x2 + 1):
    a.append((i, y1))
    a.append((i, y2))
for i in range(y1 + 1, y2):
    a.append((x1, i))
    a.append((x2, i))
n = int(input())
for _ in range(n):
    xi, yi, ri = list(map(int, input().split()))
    if len(a) > 0:
        t = len(a)
        for i in range(t-1, -1, -1):
            if calculate_distance(a[i][0], a[i][1], xi, yi) <= ri:
                del a[i]
print(len(a))