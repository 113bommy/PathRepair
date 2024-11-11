import math
for _ in range(int(input())):
    n,m=map(int,input().split())
    l,k=math.floor(m/2),math.ceil(m/2)
    if n==1:
        print(0)
    elif n==2:
        print(m)
    elif n==3:
        print(m)
    elif n==4:
        print(k*2+l)
    else:
        print(k*2+l*2)
