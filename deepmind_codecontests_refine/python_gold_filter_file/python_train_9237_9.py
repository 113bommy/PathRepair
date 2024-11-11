firstLine = input().split(" ")
n = int(firstLine[0])
vb = int(firstLine[1])
vs = int(firstLine[2])

xCoor = input().split(" ")
ux, uy = input().split(" ")
ux, uy = int(ux), int(uy)
xCoor = xCoor[1:]

index = 1
smallI = -1
smallT = -1
for i in xCoor:
    index += 1
    dis = ((int(i)-ux)**2 + uy**2)**0.5
    time = (dis/vs) + (int(i)/vb)
    if (smallT == -1):
        smallT = time
    if(smallI == -1):
        smallI = index
    if(time <= smallT):
        smallT = time
        smallI = index

print(smallI)