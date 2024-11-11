s= input()
l=[]
k=[]
m=[]
n=0
for h in s.split(" "):
    l.append(int(h))
for h in range(0,l[0]):
    a,b=input().split(" ")
    k.append(int(a))
    m.append(int(b))
if l[0]>1:
    
    for h in range(0,l[0]-1):
        if k[h+1]-k[h]+m[h]>=l[2]:
            b=(k[h+1]-k[h]+m[h])//l[2]
            n=n+b
    if (l[1]-m[l[0]-1]-k[l[0]-1])>=l[2]:
        q=(l[1]-m[l[0]-1]-k[l[0]-1])//l[2]
        n=n+q
    if k[0]>=l[2]:
        z=k[0]//l[2]
        n=n+z
elif l[0]==1:
    if l[1]-m[0]-k[0]>=l[2]:
        s=(l[1]-m[0]-k[0])//l[2]
        n=n+s
    if k[0]>=l[2]:
        z=k[0]//l[2]
        n=n+z 
else:
    n=l[1]//l[2]
print(n)    
    