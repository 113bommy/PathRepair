n = int(input())
points = sorted(set(input().split()),key=int)
j = 1
count = 0
if points[0] == 0:
    count = len(points) - 1
else:
    count = len(points)
print(count)
