n,m,q = map(int,input().split())
def gcd(a,b):
    while a!=0:
        a,b = b%a,a
    return b
g = gcd(n,m)
for _ in range(q):
    sx,sy,ex,ey = map(int,input().split())
    if g == 1:
        print("YES")
    else:
        if sx==1:
            sy=(sy-1)//(n/g)
        else:
            sy=(sy-1)//(m/g)
        if ex==1:
            ey = (ey-1)//(n/g)
        else:
            ey = (ey-1)//(m/g)
        if sy == ey:
            print("YES")
        else:
            print("NO")