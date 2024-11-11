n=int(input())
if n>=0:
    print(n)
else:
    inter=list(str(n))
    for i in range(1,len(inter)) :
        inter[i]=int(inter[i])
    if abs(n)<10:
        print(0)
        exit()
    if abs(n)<100:
        if inter[2]==0:
            print(0)
            exit()
        else:
            inter[1]=min(inter[1],inter[2])
            inter.pop(2)
            for i in inter:
                print(i,end='')
                exit()
    else:
        if inter[len(inter)-2]>inter[len(inter)-1]:
            inter[len(inter)-2]=inter[len(inter)-1]
            inter.pop(len(inter)-1)
        else:
            inter.pop(len(inter)-1)
        for i in inter:
            print(i,end='')
