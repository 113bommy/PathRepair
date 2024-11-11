n = int(input())
coordinates = []
for x in range(n):
    string = input()
    numbers = string.split()
    for y in range(4):
        numbers[y] = int(numbers[y])
    rectangle = [numbers[0], numbers[1], numbers[2], numbers[3]]
    coordinates.append(rectangle)
a = max([x[3] for x in coordinates])
b = max([x[2] for x in coordinates])
cells = 0
for x in range(1, a + 1):
    for y in range(1, b + 1):
        for z in coordinates:
            if z[0] <= x <= z[2] and z[1] <= y <= z[3]:
                cells += 1
print(cells)