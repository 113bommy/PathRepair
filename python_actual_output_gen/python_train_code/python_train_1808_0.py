n=int(input())
stat=input()
l=[0 for i in range(10)]
openRooms=[i for i in range(10)]
for i in range(n):
    if stat[i]=="L":
        l[openRooms[0]]=1
        openRooms.pop(0)
    elif stat[i]=="R":
        l[openRooms[-1]]=1
        openRooms.pop()
    else:
        l[int(stat[i])]=0
        openRooms.append(int(stat[i]))
        openRooms.sort()
for i in range(10):
    print(str(l[i]),end=" ")
