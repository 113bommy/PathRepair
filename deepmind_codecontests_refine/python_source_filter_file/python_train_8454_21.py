import math as mt 
import sys,string,bisect
input=sys.stdin.readline
import random
from collections import deque,defaultdict
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())
t=I()
for _ in range(t):
    n=I()
    l=L()
    s=sum(l)
    z=l.count(0)
    s+=z
    if(s<=0):
        print(z+(1-s))
    else:
        print(z)
    
        
