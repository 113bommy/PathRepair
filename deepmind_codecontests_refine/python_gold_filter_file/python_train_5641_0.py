t=int(input())
for i in range(t):
    b,p,f=map(int,input().split()) 
    h,c=map(int,input().split())
    z=0
    j=b//2
    if j>p+f:
        j=p+f
    else:j=b//2
    if h>c:
        if j>p:
            z=z+(h*p) 
            z=z+((j-p)*c)
        else:
            z=z+j*h
    else:
        if j>f:
            z=z+(c*f)
            z=z+((j-f)*h)
        else:
            z=z+j*c
    if j<1:z=0
    print(z)

