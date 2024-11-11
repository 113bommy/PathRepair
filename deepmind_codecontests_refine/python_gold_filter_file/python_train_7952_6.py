n,v=map(int,input().split())
k=[]
for i in range(v):
    a,b=map(int,input().split())
    k.append(a)
    k.append(b)
print(n-1)
for i in range(1,n+1):
    if i not in k:
        center=i
for i in range(1,n+1):
    if i!=center:
        print(i,center)
