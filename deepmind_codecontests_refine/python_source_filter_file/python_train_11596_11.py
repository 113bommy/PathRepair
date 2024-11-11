n,k=map(int,input().split())
a=sorted([int(i) for i in input().split()])
b=set(a)
c=list(b) 
d=len(c)
if k!=1:
    for i in c:
        if i in b:
            b.discard(i*k)
print(len(b))