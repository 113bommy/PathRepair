import math
x,d=map(int,input().split())

n=math.floor(math.log(x+1,2))
if (n-1>=d and x>10000):
    diff=x
    g=1
    arr=[]
    c=n
    while diff>0 and c<=10000:
        for i in range(g,g+n):
            arr.append(g)
        g=g+d
        tb=2**n-1
        diff=diff-tb
        n=math.floor(math.log(diff+1,2))
        c+=n
    if c>10000:
        print(-1)
    else:
        print(c)
        print(*arr)
elif (x<=10000 or n-1>=d):
    print(x)
    for i in range(1,x*d+2-d,d):
        print(i,end=' ')
    print()
else:
    diff=x
    g=1
    arr=[]
    c=n
    while diff>0:
        for i in range(g,g+n):
            arr.append(i)
        g=g+n+d-1
        tb=2**n-1
        diff=diff-tb
        n=math.floor(math.log(diff+1,2))
        c+=n
    if c>10000:
        print(-1)
    else:
        print(c)
        print(*arr)
