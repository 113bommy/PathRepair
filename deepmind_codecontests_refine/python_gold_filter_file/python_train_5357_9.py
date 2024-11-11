p,q,l,r=map(int,input().split())
x,y=set(),set()
for i in range(p):
    a,b=map(int,input().split())
    [x.add(n) for n in range(a,b+1)]
for i in range(q):
    c,d=map(int,input().split())
    [y.add(n) for n in range(c,d+1)]
p=0
for i in range(l,r+1):
    for j in y:
        if j+i in x:
            p+=1
            break
print(p)