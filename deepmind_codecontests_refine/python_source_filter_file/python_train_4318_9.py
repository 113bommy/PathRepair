import math
import sys,string,bisect
input=sys.stdin.readline
from collections import deque,defaultdict
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())
def line(l,p):
    d=(l[0]*p[0]+l[1]*p[1]+l[2])
    if(d>0):
        return 1
    elif(d<0):
        return -1
    return 0
def intersection(L1, L2):
    D  = L1[0] * L2[1] - L1[1] * L2[0]
    Dx = L1[2] * L2[1] - L1[1] * L2[2]
    Dy = L1[0] * L2[2] - L1[2] * L2[0]
    if D != 0:
        x = Dx / D
        y = Dy / D
        return [x,y]
    else:
        return False
s=L()
e=L()
n=I()
lines=[]
for i in range(n):
    l=L()
    lines.append(l)
p1=[s[0],e[1]]
p2=[e[0],s[1]]
c1=0
c2=0
c3=0
c4=0
c5=0
for i in range(n):
    if(line(lines[i],p1)*line(lines[i],s)<0):
        c1+=1
    if(line(lines[i],p2)*line(lines[i],s)<0):
        c2+=1
    if(line(lines[i],p1)*line(lines[i],e)<0):
        c3+=1
    if(line(lines[i],p2)*line(lines[i],e)<0):
        c4+=1
    if(line(lines[i],s)*line(lines[i],e)<0):
        c5+=1
print(min(c1+c3,c2+c4,c5))
