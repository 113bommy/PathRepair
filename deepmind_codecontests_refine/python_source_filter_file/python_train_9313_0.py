n=int(input())
twoback={}
twofront={}
for i in range(n):
    front,back=[int(x) for x in input().split(' ')]
    twoback[front]=back
    if not back in twoback:
        twoback[back]=-1
    twofront[back]=front

if n%2==0:
    outevens=[]
    outodds=[]
    fromleft=0
    fromright=0
    for i in range(int(n/2)):
        outevens.append(twoback[fromleft])
        fromleft=outevens[-1]
        outodds.append(twofront[fromright])
        fromright=outodds[-1]
    tosendout=""
    for c, d in zip(outevens,reversed(outodds)):
        tosendout+=str(c)+" "+str(d)+" "
    print(tosendout.rstrip(" "))
else:
    fromleft=0
    for key,value in twoback.items():
        if value==-1:
            fromright=key
            break
    outevens=[]
    outodds=[fromright]
    for i in range(int(n/2)):
        outevens.append(twoback[fromleft])
        fromleft=outevens[-1]
        outodds.append(twofront[fromright])
        fromright=outodds[-1]
    for c,d in zip(outevens,reversed(outodds)):
        print(c,d,end=" ")
    print(outodds[0])

