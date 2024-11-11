import math as mt 
import sys,string
input=sys.stdin.readline
import random
from collections import deque,defaultdict
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())
c,d=M()
n,m=M()
k=I()
if(n*m<=k):
    print(0)
else:
    t=n*m-k
    if(n/c<1/d):
        print(d*t)
    else:
        q=t//n
        p=t%n
        print(min(q*c+1,q+p*d))
