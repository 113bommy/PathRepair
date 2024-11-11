n = [int(x) for x in input().split()]
start = (n[1], n[2])
slope_set = set()
for x in range(n[0]):
    points = input().split()
    point = [int(y) for y in points]
    val_x = point[0] - start[0]
    val_y = point[1] - start[1]
    if val_x == 0:
        slope_set.add(('x', point[0]))
    else:
        slope_set.add((point[1] - start[1])/(point[0] - start[0]))
print(len(slope_set))