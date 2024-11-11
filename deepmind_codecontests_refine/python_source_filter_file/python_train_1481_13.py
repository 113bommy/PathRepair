def R(): return map(int, input().split())
def I(): return int(input())
def S(): return str(input())

def L(): return list(R())

from collections import Counter 

import math
import sys

def search(b,bit):
    if bit<0 or len(b)==0:
        return 0

    r=[]
    l=[]
    for x in b:
        if x>>bit==1:
            r.append(x)
        else:
            l.append(x)

    if len(l)==0:
        return search(r,bit-1)

    if len(r)==0:
        return search(l,bit-1)

    return min(search(r,bit-1),search(l,bit-1))+2**bit

n=I()
a=L()

print(search(a,31))
