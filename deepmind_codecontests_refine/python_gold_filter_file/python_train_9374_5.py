#dice
D=[int(i) for i in input().split()]
Os=input()
for i in range(len(Os)):
    if Os[i]=="N":
        t=D[0]
        D[0]=D[1]
        D[1]=D[5]
        D[5]=D[4]
        D[4]=t
    elif Os[i]=="S":
        t=D[0]
        D[0]=D[4]
        D[4]=D[5]
        D[5]=D[1]
        D[1]=t        
    elif Os[i]=="E":
        t=D[0]
        D[0]=D[3]
        D[3]=D[5]
        D[5]=D[2]
        D[2]=t        
    elif Os[i]=="W":
        t=D[0]
        D[0]=D[2]
        D[2]=D[5]
        D[5]=D[3]
        D[3]=t        
print(D[0])