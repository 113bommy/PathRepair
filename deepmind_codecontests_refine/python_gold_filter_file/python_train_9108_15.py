n = int(input())
coords = []
for i in range(n):
    coords.append([int(i) for i in input().split()])
if n == 1:
    print(-1)
elif n == 2:
    if coords[0][0] != coords[1][0] and coords[0][1] != coords[1][1]:
        print(abs((coords[0][0]-coords[1][0]) * (coords[0][1]-coords[1][1])))
    else:
        print(-1)
else:
    r = 0
    for coord1 in coords:
        for coord2 in coords:
            if coord1[0] != coord2[0] and coord1[1] != coord2[1]:
                print(abs((coord1[0]-coord2[0]) * (coord1[1]-coord2[1])))
                r = 1
                break
        if r == 1:
            break
