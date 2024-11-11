a,b,c,d=map(int,input().split(' '))
if 2*c<d or 2*d<c:
    print("-1")
else:
    if d<=c:
        print(2*a)
        print(2*b)
        print(2*d)
    else:
        print(2*a)
        print(2*b)
        print(2*c)
    
    
