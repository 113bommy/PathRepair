import math
from collections import OrderedDict
from collections import Counter
from itertools import combinations
from itertools import accumulate
import operator
import bisect
#a= list(map(int, input("").strip().split()))[:n]
def solve(x,d):
    c=x
    e=[]
    f=d%4
    for i in range(4):
        m=i+1
        if c & 1:
            c+=m
        else:
            c-=m
        e.append(c)
    if f==2 or f==0:
        if f==0:
            f+=4
        print(e[f-1])
        return
    else:
        d-=1
        g=d//4
        if f==1:
            if g & 1:
                print(e[f-1]+g*4)
                return
            else:
                print(e[f-1]-g*4)
                return
        else:
            if g & 1:
                print(e[f-1]-g*4)
                return
            else:
                print(e[f-1]+g*4)
                return
            
t=int(input(""))
for i in range(t):
    x,d= list(map(int, input("").strip().split()))[:2]
    solve(x,d)