a, b = map(int, input().split())

cand_a = []
cand_b = []
for i in range(1, 1000):
    j = 1
    while j * j + i * i <= 1000000:
        if i * i + j * j == a * a:
            cand_a.append((i, j))
        if i * i + j * j == b * b:
            cand_b.append((-i, j))
        j += 1

def dist(a, b):
    return (a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2

for point_a in cand_a:
    for point_b in cand_b:
        if point_b[0] != point_b[1] and dist(point_a, point_b) == a * a + b * b:
            print("YES")
            print("0 0")
            print("%d %d" % (point_a[0], point_a[1]))
            print("%d %d" % (point_b[0], point_b[1]))
            exit(0)

print("NO")

