t=int(input())
for i in range(t):
    n,x=map(int,input().split())
    maxx=0
    maxxx=0
    for o in range(n):
        d,h=map(int,input().split())
        if (d-h>maxx):
            maxx=d-h
        if (d>maxxx):
            maxxx=d
    if (maxx!=0)or(maxxx>=x):
        if (maxxx>=x):
            print(maxxx)
        else:
            if (x-maxxx)%maxx>0:
                u=1
            else:
                u=0
            print((x-maxxx)//maxx+u+1)
    else:
        print(-1)