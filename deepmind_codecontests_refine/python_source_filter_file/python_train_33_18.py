a,b,c=map(int,input().split())
if a:
    d=b**2-4*a*c
    if d<0:
        ans=[0]
    elif d==0:
        ans=[1,-b/(2*a)]
    else:
        ans=[2]+sorted([(b-d**0.5)/(2*a),(b+d**0.5)/(2*a)])
else:
    if b:
        ans=[1, -c/b]
    else:
        if c:
            ans=[0]
        else:
            ans=[-1]
print(*ans)
