import math as mt 
import sys,string
input=sys.stdin.readline
from collections import defaultdict
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())
from collections import defaultdict


def check(a,b,c,d):
    if(a==c or b==d):
        return True
    if(abs(a-c)==abs(b-d)):
        return True
    return False
n=I()
v=defaultdict(int)
bx,by=M()
ax,ay=M()
cx,cy=M()
l=[ax,bx,cx]
y=[ay,by,cy]
l.sort()
y.sort()
if(l[1]==bx or y[1]==by):
    print("NO")
else:
    print("YES")
