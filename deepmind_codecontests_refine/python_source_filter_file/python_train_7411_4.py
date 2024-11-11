from math import gcd
q=int(input())
for i in range(q):
    n=int(input())
    p=[10**1000]+[int(x) for x in input().split()]
    x,a=[int(x) for x in input().split()]
    y,b=[int(x) for x in input().split()]
    k=int(input())
    p.sort(reverse=True)
    flag=False
    l=1
    r=n
    if x<y:
        x,y=y,x
        a,b=b,a
    z=(a*b)//gcd(a,b)
    while r-l>1:
        mid=(l+r)//2
        pointer=1
        counter=0
        for j in range(z,mid+1,z):
            counter+=(p[pointer]*(x+y)//100)
            pointer+=1
        for j in range(a,mid+1,a):
            if j%z!=0:
                counter+=(p[pointer]*x//100)
                pointer+=1
        for j in range(b,mid+1,b):
            if j%z!=0:
                counter+=(p[pointer]*y//100)
                pointer+=1
        if counter>=k:
            flag=True
            r=mid
        else:
            l=mid
    mid=r
    pointer=1
    counter=0
    for j in range(z,mid+1,z):
        counter+=(p[pointer]*(x+y)//100)
        pointer+=1
    for j in range(a,mid+1,a):
        if j%z!=0:
            counter+=(p[pointer]*x//100)
            pointer+=1
    for j in range(b,mid+1,b):
        if j%z!=0:
            counter+=(p[pointer]*y//100)
            pointer+=1
    if counter>=k:
        print(r)
    else:
        print(-1)
    
                
            
    
    
