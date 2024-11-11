t=int(input())
while(t):
    t-=1
    n,x,a,b=map(int,input().split())
    if a>b:
        c=a-1
        d=b-1
    else:
        c=b-1
        d=a-1
    temp=x
    while(temp>0):
        temp-=1
        if c+1<n:
            c=c+1
        elif d-1>0:
            d=d-1
        else:
            break
    print(c-d)
