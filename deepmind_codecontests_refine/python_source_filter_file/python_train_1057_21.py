import math as mt 
import sys,string,bisect
input=sys.stdin.readline
from collections import deque,defaultdict
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())
x,y,z=M()
ans=(x+y)//z
if(z-x%z>y%z):
    if(z-y%z>x%z):
        print(ans,0)
    else:
        print(ans,x%z)
else:
    if(z-y%z>x%z):
        print(ans,y%z)
    else:
        print(ans,min(x%z,y%z))
