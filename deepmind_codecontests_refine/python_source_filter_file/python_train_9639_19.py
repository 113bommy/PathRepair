import math
import queue

from itertools import permutations

def win(x,y):
    if x==0:
        k=y//22
        if k%2==1:
            return 1
        else:
            return 2
    elif x==1:
        if y<12:
            return 2
        k=1+(y-12)//22
        if k%2==1:
            return 1
        else:
            return 2
    elif y<24:
        if y<2:
            return 2
        elif ((x-2)>=1) and ((y-2)>=12):
            return win(x-3,y-14)
        elif (x-2)>=2 and (y-2)>=2:
            return win(x-4,y-4)
        else:
            return 1
    
    k=min(x//2,y//24)
    x-=2*k
    y-=y*24
    return win(x,y)

m,n=map(int, input().split())

if win(m,n)==1:
    print("Ciel")
else:
    print("Hanako")