import math
t=int(input())
for _ in range(t):
    n=int(input())
    p=0
    a=list(map(int,input().split()))
    d={}
    for i in a:
        if i in d:
            d[i]+=1
        else:
            d[i]=1
    e=list(d.values())
    z=1
    for i in e:
        if(i%2==1):
            z=0
            break
    if(z==0):
        print("NO")
        continue
    p=1
    for i in a:
        p=p*pow(i,1/(2*n))
    if(abs(p-round(p))<0.0000001):
        print("YES")
    else:
        print("NO")