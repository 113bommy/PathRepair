t=int(input())
while t!=0:
    t-=1
    k=0
    c=0
    x,y,a,b=tuple(map(int,input().split()))
    if (y-x)%(a+b)==0:
        print((y-x)%(a+b))
    else:
        print(-1)