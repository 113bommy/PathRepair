n, l = [int(m) for m in input().split()]
points = sorted([int(m) for m in input().split()])
a = []
j = -1 * points[0]
for i in range(n):
    a.append((points[i] - j) / 2)
    j = points[i]
a.append(n - points[n - 1])
print(max(a))