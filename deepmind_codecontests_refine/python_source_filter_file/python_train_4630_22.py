x=int(input())
p=list(map(int,input().split()))
z=""
for n in range(x):
    z=z+str(p[n])
a=z.count("1")
b=z.count("2")
c=z.count("3")
if a!=0 and b!=0 and c!=0:
    if a<=b:
        d=a
    else:
        d=b
    if d<=c:
        w=d
    else:
        w=c
    print(w)
    d=1    
elif a==0 or b==0 or c==0:
    print("0")
    d=0
if d==1:
    k=[]
    kk=[]
    kkk=[]
    for n in range(x):
        if p[n]==1:
            k.append(n)
    for n in range(x):
        if p[n]==2:
            kk.append(n)
    for n in range(x):
        if p[n]==3:
            kkk.append(n)
               
    
    for n in range(w):
        print(k[n],kk[n],kkk[n])        
        
    