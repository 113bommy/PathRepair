from sys import stdin
import math

N = int(stdin.readline())

points = []

for n in range(N):
    x, y = map(int, stdin.readline().split())

    points.append((x * x + y * y, x, y, n))

points.sort()

p0 = points[0]
p1 = None
p1_i = 0
for i in range(1, N):
    p = points[i]
    if p[1] != p0[1] and p[2] != p0[2]:
        p1 = p
        p1_i = i
        break

dx = p0[1] - p1[1]
dy = p0[2] - p1[2]
for d, x, y, i in points[p1_i + 1:]:
    dx2, dy2 = p0[1] - x, p0[2] - y

    if dx * dy2 != dy * dx2:
        print(p0[3] + 1, p1[3] + 1, i + 1)
        break
