p,q,l,r=map(int,input().split())
x=[]
for i in range(p):
    x.append(list(map(int,input().split())))
y=[]
for i in range(q):
    y.append(list(map(int,input().split())))
ans=0
for i in range(l,r+1):
    f=0
    for j in x:
        for k in y:
#             print()
#             print(k[0]+i,k[1]+i)
#             print(j[0],j[1])
            if(k[0]+i<=j[0] and k[1]+i>=j[0]):
                f=1
            if(k[0]+i>=j[0] and k[0]+i<=j[1]):
                f=1
    if(f):
        ans+=1
print(ans)