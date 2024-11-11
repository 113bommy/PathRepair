def p(a,b,x,y,n):
    if a-x<=n:
        n-=(a-x)
        a=x
        if b-y<=n:
            b=y
        else:
            b=b-n
        return a*b
    else:
        a=a-n
        return a*b
t=int(input())
for _ in range(t):
    a,b,x,y,n=map(int,input().split())
    ans1=p(a,b,x,y,n)
    ans2=p(b,a,y,x,n)
    print(ans1,ans2)