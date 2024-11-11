t=int(input())
for i in range(t):
    blank=input()
    total=list(map(int,input().split()))
    pos=list(map(int,input().split()))
    tmp=list(map(int,input().split()))

    cells=total[0]
    cons=total[1]
    for i in range(len(pos)):
        pos[i]=pos[i]-1
    di={}
    for i in range(cons):
        di[pos[i]]=tmp[i]
    temp=[]
    pos.sort()
    for i in pos:
        temp.append(di[i])
    print(pos)
    print(temp)


    if cons==1:
        lasttemp=[]
        for i in range(pos[0]):
            lasttemp.append(temp[0]+pos[0]-i)
        for i in range(pos[0],cells,1):
            lasttemp.append(temp[0]+i-pos[0])
        print(*lasttemp)

    if cons>1:
        diR={}
        diL={}

        for i in range(pos[0]): diR[i]=di[pos[0]]+pos[0]-i
        diR[pos[0]]=di[pos[0]]
        for i in range(pos[0]+1,cells,1):
            if i not in di.keys(): diR[i]=diR[i-1]+1
            else: diR[i]=min(di[i],diR[i-1]+1)
        #print(diR)

        for i in range(pos[len(pos)-1]+1,cells,1): diL[i]=di[pos[len(pos)-1]]-pos[len(pos)-1]+i
        diL[pos[len(pos)-1]]=di[pos[len(pos)-1]]
        for i in range(pos[len(pos)-1]-1,-1,-1):
            if i not in di.keys(): diL[i]=diL[i+1]+1
            else: diL[i]=min(di[i],diL[i+1]+1)


        #print(diL)

        lasttemp=[]
        for i in range(cells):
            lasttemp.append(min(diR[i],diL[i]))
        print(*lasttemp)
