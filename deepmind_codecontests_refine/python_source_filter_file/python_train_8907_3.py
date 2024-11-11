import math
n,m=map(int,input().split())
d=math.gcd(n,m)
k=1
l=[]
for i in range(k,int(d**0.5)+1):
    if d%i==0:
        if d//i==i:
            l.append(i)
        else:
            l.append(n//i)
            l.append(i)
l.sort()
for _ in range(int(input())):
    a,b=map(int,input().split())
    m=-1
    for i in l:
        if i>=a and i<=b:
            m=max(i,m)
    print(m)
        
        