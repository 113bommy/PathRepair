import math
t = 1
t = int(input())
for tt in range(t):
    a,b,c,d = map(int,input().split())
    s = a - b
    if s > 0 and d > c:
        print(-1)
    elif s <= 0:
        print(b)
    else:
        print(int(b + ((math.ceil(a - b) / (c - d)) * c)))