import math
r=int(input())
for i in range(r):
    n,d = map(int,input().split())
    if n<d:
        d=n
        print(d*(d-1)//2 +1)
    else:
        d=d
        print(d*(d+1)//2 )