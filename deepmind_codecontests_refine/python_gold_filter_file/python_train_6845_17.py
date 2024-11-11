n,p=map(int,input().split())
l=list(map(int,input().split()))
d=[]
k=[]
for i in range(0,n,1):
    if l[i] not in d:
        d.append(l[i])
        k.append(i+1)
if len(d)<p:
    print("NO")
else:
    print("YES")
    print(*k[:p:])


    
    

