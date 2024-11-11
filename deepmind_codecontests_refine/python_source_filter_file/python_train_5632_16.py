n=list(map(int,input().split()))
t=list(map(int,input().split()))
tx=set(t)

def check(x):
    z=0
    w=0
    for p in range(1,x):
        for i in tx:
            z+=int(t.count(i)/p)
        if z>=n[0]:w=p
        z=0
    return w
    
    

maxi=[]
for i in tx:
    a=check(t.count(i))
    maxi.append(a)
maxi.sort()
if len(maxi)==0:print(0)
else: print(maxi[len(maxi)-1])
