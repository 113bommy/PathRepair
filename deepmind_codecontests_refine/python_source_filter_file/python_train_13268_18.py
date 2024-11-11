x = int(input())
i = 0
z = 0
for i in range(x):
    y = input().split()
    y1 = int(y[0])
    y2 = int(y[1])
    if(y2 == 1):
        z += 0
    elif(y2 == y1):
        z += 0
    elif(y2 == 2):
        if(y1 == 0):
            z += 1
        else:
            z += 0
    elif(y2 > y1):
        if((y2 - (y1-1)) > 1 ):
            z += 1
        else:
            z += 0
    i += 1
print(z)
