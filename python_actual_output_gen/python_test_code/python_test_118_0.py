n,k=map(int,input().split())
data=input()
bag=dict()
prev=data[0]
val=0
for q in range(1,n):
    if(data[q]==prev):
        val+=1
    else:
        if(prev in bag):
            bag[prev].append(val)
        else:
            bag[prev]=[val]
        val=1
        prev=data[q]
if(prev in bag):
    bag[prev].append(val)
else:
    bag[prev]=[val]
ans=0
for key,val in bag.items():
   #print(val)
    temp=0
    for q in val:
        temp+=(q//k)
    ans=max(ans,temp)
print(ans)