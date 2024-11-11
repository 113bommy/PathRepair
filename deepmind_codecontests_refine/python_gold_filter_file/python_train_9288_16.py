import math
for _ in [0]*int(input()):
    n,d=map(int,input().split())
    sqrtd=int(d**0.5)
    if d<=n or sqrtd-1+math.ceil(d/(sqrtd))<=n:
        print("YES")
    else:
        print("NO")