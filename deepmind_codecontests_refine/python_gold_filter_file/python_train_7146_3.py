r,x1,y1,x2,y2=map(int,input().split())
if (x2-x1)**2+(y2-y1)**2>=r*r:
    print(x1,y1,r)
    exit()
if x1==x2:
    if y2<y1:
        print(x1,y2+(y1+r-y2)/2,(y1+r-y2)/2)
    else:
        print(x1,y2-(y2-y1+r)/2,(y2-y1+r)/2)
else:
    k=(y2-y1)/(x2-x1)
    b=y1-k*x1
    B=b+0
    a=k*k+1
    c=x1*x1+b*b-2*b*y1+y1*y1-r*r
    b=2*k*b-2*x1-2*k*y1
    d=b*b-4*a*c
    X1=(-b+d**0.5)/(2*a)
    X2=(-b-d**0.5)/(2*a)
    Y1=k*X1+B
    Y2=k*X2+B
    r1=((X1-x2)**2+(Y1-y2)**2)**0.5
    r2=((X2-x2)**2+(Y2-y2)**2)**0.5
    if r1>r2:
        print((x2+X1)/2,(y2+Y1)/2,r1/2)
    else:
        print((x2+X2)/2,(y2+Y2)/2,r2/2)
    
    
