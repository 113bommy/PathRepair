import math
import sys
t=int(input())
for te in range(t):

    d=[]
    h=[]

    n,x=map(int,input().split())
    for i in range(n):
        d1, h1 = map(int, input().split())
        d.append(d1)
        h.append(h1)
    dmax = max(d)
    if dmax >= x:
        print(n)
    else:
        dhmax = -sys.maxsize
        for i in range(n):
            dhmax = max(d[i] - h[i], dhmax)
        if dhmax <= 0:
            print(-1)
        else:
            print(math.ceil((x - dmax) / dhmax)+1)




