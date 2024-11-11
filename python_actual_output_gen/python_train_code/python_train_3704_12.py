l,r,a=map(int,input().split(' '))
if l<r:
    x=r-l
    if a<x:
        l=l+a
        print(2*l)
    else:
        x=x-a
        r=r+x//2
        print(2*r)
elif l==r:
    r=r+a//2
    print(r*2)
else:
    x=l-r
    if a<x:
        r=r+a
        print(2*r)
    else:
        x=x-a
        l=l+x//2
        print(2*l)
