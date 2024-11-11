import math
for xyzc in range(0,int(input())):
    n,g,b=map(int,input().split())
    gd=math.ceil(n/2)
    d=0
    d+=(gd//g)*(g+b)
    if gd%g==0:
        d-=b
    else:
        d+=(gd%g)
    print(d)