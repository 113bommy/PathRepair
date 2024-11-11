n,k,p = map(int,input().split())
lis = list(map(int,input().split()))
q=k-p
ev=[]
od=[]
res=[]
for i in lis:
    if i%2:
        od.append(i)
    else:
        ev.append(i)
res=[]
while p:
    if len(ev)>0:
        res.append([ev.pop()])
    elif len(od)>1:
        res.append([od[-1],od[-2]])
        del od[-2:]
    else:
        print("NO")
        exit()
    p-=1    
while q:
    if len(od)>0:
        res.append([od.pop()])
    else:
        print("NO")
        exit()
    q-=1
if len(ev):
    res[0]+=ev
if len(od)%2==0:
    res[0]+=od
else:
    print("NO")
    exit()
print("YES")    
for i in res:
    print(len(i),*i)


        

