import math
t = int(input())
for i in range(t):
    n , x = map(int,input().split())
    m=md=0
    for j in range(n):
        d , h = map(int,input().split())
        m = max(m,d)
        md = max(md,d-h)
    if md<=0:
        if m>=x:
            print(1)
        else:
            print(-1)
    else:
        s = 1 + math.ceil((x-m)/md)
        print(s)               
 
       
