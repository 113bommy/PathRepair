import math
inp=lambda:map(int,input().split())
t = int(input())
for _ in range(t):
    x1, y1, x2, y2 = inp()

    if x1==x2 or y1==y2:
        print(1)
    
    else:
        print(abs(x1-x2)+abs(y1-y2))
    