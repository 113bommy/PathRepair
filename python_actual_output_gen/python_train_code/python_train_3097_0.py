n = int(input())

points = []

for i in range(0, n):
    points.append(list(map(int, input().split())))

nrt = 0

for p in points:
    nrt += (abs(p[3] - p[0]) + 1) * (abs(p[2] - p[0]) + 1)

print(nrt)