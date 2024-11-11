t = input()
temp = t.split()
n = int(temp[0])
s = int(temp[1])
t = int(temp[2])
positionList = []
o = input()
temp = o.split()
positionList = [int(i) for i in temp]
shuffle = 0
tempVar = s - 1
while(True):
    if (shuffle > n):
        break
    if (positionList[tempVar] == t):
        shuffle += 1
        break
    elif (positionList[tempVar] != t):
        shuffle += 1
        tempVar = positionList[tempVar] - 1
if (shuffle > n):
    print(-1)
elif (shuffle == 1):
    print(0)
else:
    print(shuffle)
