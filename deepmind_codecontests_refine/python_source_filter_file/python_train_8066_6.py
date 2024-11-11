n=int(input())
l=[]
l1=[0 for i in range(1000001) ]
L=[]
L1=[0 for i in range(1000001) ]
k=0
for i in range(n) :
    a,b=map(int,input().split())
    if a>0 :
        l.append(a)
        l1[a]=b
    else :
        L.append(abs(a))
        L1[abs(a)]=b
l=sorted(l)
L=sorted(L)
p=0
for i in range(min(len(l),len(L))) :
    k=k+l1[l[i]]
    k=k+L1[abs(L[i])]
    p=p+1
if len(l)>len(L) :
    k=k+l1[l[p]]
if len(l)<len(L) :
    k=k+L1[abs(L[-1])]
print(k)
    
        
        
