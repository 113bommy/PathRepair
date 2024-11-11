
[size_x, size_y, x, y] = [int(x) for x in input().split()]

s = input()

coord = [x, y]

direction = {
    'U':[-1,0],
    'D':[1,0],
    'L':[0,-1],
    'R':[0,1]
}

visited = {}

blown = 0

output = []

for c in s:
    if (coord[0],coord[1]) not in visited:
        output.append(1)
        visited[(coord[0],coord[1])] = True
        blown += 1
    else:
        output.append(0)

    coord[0] += direction[c][0]
    coord[0] = max(1, coord[0])
    coord[0] = min(size_x, coord[0])

    coord[1] += direction[c][1]
    coord[1] = max(1, coord[1])
    coord[1] = min(size_y, coord[1])

# print(blown, size_x*size_y)
output.append(size_x*size_y- blown)

print(" ".join(str(x) for x in output))