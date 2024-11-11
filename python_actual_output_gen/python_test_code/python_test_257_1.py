I=lambda:map(int,input().split())
n,m,k,l=I()
if m>n or (l>=n) :
    print(-1)
else:
    x= (-(-l//m)*(1+k//l))
    if x*m>n:
        print(-1)
    else:
        print(x)