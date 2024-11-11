le=int(input())
li=list(map(int,input().split()))
lj=[li.count(1),li.count(3),li.count(3)]
l=min(lj)
print(l)
while(l):
    lx=[]
    for x in range(1,4):
        ind=li.index(x)
        lx.append(ind+1)
        li[ind]=-99
    print(lx)
    l-=1