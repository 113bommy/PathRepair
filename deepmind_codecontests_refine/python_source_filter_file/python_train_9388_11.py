from math import ceil
for i in range(int(input())):
    n,x = map(int,input().split())
    a = b = 0
    for i in range(n):
        d,h = map(int,input().split())
        a = max(a,d)
        b = max(b,d-h)
    if b<=0:
        print(-1)
    elif a>x:
        print(1)
    else:
        print(ceil((x-a)/b)+1)
    
            