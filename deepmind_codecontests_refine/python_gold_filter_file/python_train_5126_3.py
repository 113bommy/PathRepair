for t in range(int(input())):
    n,x=map(int,input().split())
    a=sorted(set(map(int,input().split())))
    n=len(a)
    b=a[0]-1
    ans=min(a[0],x+(1 if a[0]-x==1 else 0))
    for i in range(1,n):
        b+=(a[i]-a[i-1]-1)
        if b>x:
            b-= (a[i] - a[i - 1] - 1)
            ans=a[i-1]+(x-b)
            b = x+1
            break
    if b<=x:
        ans=a[-1]+(x-b)
    print(ans)
