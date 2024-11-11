t=int(input())
for _ in range(t):
    n,a,b,h=map(int,input().split())
    s=list(input())
    k=s.count('1')
    m=s.count('0')
    if a==b:
        print(a*n)
    elif a>b:
        p=m*a+k*b
        q=m*h+n*b
        r=k*h+n*a
        ans=min(p,q,r)
        print(ans)
        