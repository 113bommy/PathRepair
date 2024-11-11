n=int(input())
slist=list(map(int,input().split()))
total=sum(slist)
s=slist[0]
mlist=[]
for i in range(0,len(slist)):
    if(slist[i]<=(slist[0]//2)):
        s=s+slist[i]
        mlist.append(i)
if(s>(total//2)):
    mlist.insert(0,1)
    mlist=list(set(mlist))
    print(len(mlist))
    for i in range(0,len(mlist)):
        print(mlist[i],end=" ")
else:
    print(0)