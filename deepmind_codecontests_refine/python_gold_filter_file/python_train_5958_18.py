import math
for i in range(int(input())):
    n,g,b=map(int,input().split())
    s=math.ceil(n/2)
    x=(s//g)*(g+b)
    if s%g==0:
        print(max(n,x-b))
    elif s%g!=0:
        x+=(s%g)
        print(max(n,x))