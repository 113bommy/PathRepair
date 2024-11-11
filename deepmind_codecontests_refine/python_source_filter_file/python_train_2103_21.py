import math
for _ in range(int(input())):
    a,b,c,d,k=map(int,input().split())
    count_pens=0
    count_pencils=0
    x=math.ceil(a/b)
    y=math.ceil(b/d)

    if(x+y<=k):
        print(x,y)
    else:
        print(-1)
