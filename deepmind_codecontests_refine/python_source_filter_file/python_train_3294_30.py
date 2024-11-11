import math
for _ in range(int(input())):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    if k==1:
        print(max(n-a[0],a[0]-1)+1)
    elif k==n:
        print(1)
    else:
        x,y,h=a[0]-1,n-a[-1],0
        for i in range(k-1):
            if a[i+1]-a[i]-1>h:
                h=a[i+1]-a[i]-1
        z=math.ceil(h/2)
        print(max(x,max(y,z)))