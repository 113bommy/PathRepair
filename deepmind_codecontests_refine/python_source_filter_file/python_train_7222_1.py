values = []
yes = False

for i in range(4):
    line = list(input())

    seg1 = line[:2]
    seg2 = line[1:3]
    seg3 = line[2:4]

    arr = [0, 0, 0]

    if seg1.count("#") == 1:
        arr[0] = 1
    elif seg1.count("#") == 2:
        arr[0] = 2

    if seg2.count("#") == 1:
        arr[1] = 1
    elif seg2.count("#") == 2:
        arr[1] = 2

    if seg3.count("#") == 1:
        arr[2] = 1
    elif seg3.count("#") == 2:
        arr[2] = 2

    values.append(arr)

for i in range(len(values)):
    values[i].append(0)
values.append([0, 0, 0, 0])

for row in range(4):
    for column in range(3):
        if (values[row][column] == 2 and values[row + 1][column] == 1) or (values[row][column] == 1 and values[row + 1][column] == 2) \
        or (values[row][column] == 2 and values[row + 1][column] == 2) or (values[row][column] == 0 and values[row + 1][column] == 0) \
        or (values[row][column] == 1 and values[row + 1][column] == 0) or (values[row][column] == 0 and values[row + 1][column] == 1) :
            yes = True

if yes:
    print("YES")
else:
    print("NO")