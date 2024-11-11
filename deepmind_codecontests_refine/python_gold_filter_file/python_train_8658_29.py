n=[int(i) for i in input().split()]
l,s,r=n[0],n[1],n[2]
z=[(2**(int(i))) for i in range(s)]
z1=[(2**(int(i))) for i in range(r)]
if(l==1):
    print(l,l)
else:
    y=0
    if(s==1):
        x=l
    else:
        a=l-s+1
        x=a
        for i in range(1,l-a+1):
            x+=(2**i)
    for i in range(0,r):
        y+=(2**i)
    y+=((2**(i))*(l-r))
    print(x,y)