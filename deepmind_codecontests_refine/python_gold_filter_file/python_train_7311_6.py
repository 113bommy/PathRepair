n=int(input())
l=input().split()
li=[int(i) for i in l]
sumi=[0]
sumnow=0
for i in range(n):
    sumnow+=li[i]
    sumi.append(sumnow)

hashi=dict()
lcpy=list(sumi)
count=0
fromwhich=0
for i in range(n+1):
    if sumi[i] not in hashi:
        hashi[sumi[i]]=(1,i)
        count+=len(hashi)-1
    else:
        x=hashi[sumi[i]]
        y=x[1]
        for j in range(fromwhich,y+1):
            del hashi[sumi[j]]
        hashi[sumi[i]]=(1,i)
        count+=len(hashi)-1
        fromwhich=y+1



print(count)