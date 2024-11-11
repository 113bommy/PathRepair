from math import ceil
for _ in range(int(input())):
    a,b=map(int,input().split())
    if 2*a>b:
        print(-1,-1)
    else:
        print(a,2*a)
    