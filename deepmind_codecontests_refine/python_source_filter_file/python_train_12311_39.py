from math import *
for _ in range(int(input())):
    a,b,c=map(int,input().split())
    if a>=c:print(-1,b)
    else:
        if a>c/b:print(1,2)
        elif a<=c/b:print(1,-1)