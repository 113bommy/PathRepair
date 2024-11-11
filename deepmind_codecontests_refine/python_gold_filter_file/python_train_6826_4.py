n = int(input())
names = []
points = []
for _ in range(n):
    a = input().split()
    names.append(a[0])
    b = [int(i) for i in a[1:]]
    point = 50 * (2 * b[0] - b[1])
    for i in range(5):
        point += b[i+2]
    points.append(point)
max_point = points[0]
max_name = names[0]
for i in range(n):
    if max_point < points[i]:
        max_point = points[i]
        max_name = names[i]
print(max_name)
