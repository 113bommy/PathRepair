import math
m=int(input())
for i in range(m) :
    n=int(input())
    i=0
    listminer=[]
    listmines=[]
    while i<2*n :
        x, y = [int(x) for x in input().split()]
        if x==0 and y==0 :
            exit()
        i=i+1
        if x==0 :
            listminer.append(y)
            continue
        if y==0 :
            listmines.append(x)
            continue

    listminer.sort()
    listmines.sort()
    j=0
    energy=0
    while j<n :
        energy=energy+math.sqrt(listmines[j]*listmines[j]+listminer[j]*listminer[j])
        j=j+1
    print(energy)
