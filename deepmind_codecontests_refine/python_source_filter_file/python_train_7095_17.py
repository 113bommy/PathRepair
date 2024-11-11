from sys import stdin,exit
l=list(map(int,stdin.readline().split()))
n,a,x,b,y=l[0],l[1],l[2],l[3],l[4]
p1,p2=0,0
if a<x:
    p1=x-a
else:
    p1=n-(a-x)
if b>y:
    p2=y-b
else:
    p2=n-(y-b)
if a==b or x==y:
    print("YES")
else:
    k=[]
    j=[]
    for i in range(p1):
        a=a%n + 1
        k.append(a)
    for i in range(p2):
        b=b%n-1
        if b==0:
            b=n
        j.append(b)
    s,d=0,0
    for i in k:
        s+=1
        d=0
        for f in j:
            d+=1
            if i==f and s==d:
                print("YES")
                exit()
    print("NO")