# coding: utf-8
# Your code here!

import sys
n = int(input())

inf = float("inf")
u=d=l=r=0
umin = inf
umax = -inf
dmin = inf
dmax = -inf
lmin = inf
lmax = -inf
rmin = inf
rmax = -inf

xmin = inf
xmax = -inf
ymin = inf
ymax = -inf
xx=yy=0

for j in range(n):
    x,y,D = [i for i in input().split()]
    x=int(x); y=int(y)
    if D == "U":
        umin = min(umin,y)
        umax = max(umax,y)
        u=1
        xmin = min(xmin,x)
        xmax = max(xmax,x)
        xx=1
    if D == "D":
        dmin = min(dmin,y)
        dmax = max(dmax,y)
        d=1
        xmin = min(xmin,x)
        xmax = max(xmax,x)
        xx=1
    if D == "L":
        lmin = min(lmin,x)
        lmax = max(lmax,x)
        l=1
        ymin = min(ymin,y)
        ymax = max(ymax,y)
        yy=1
    if D == "R":
        rmin = min(rmin,x)
        rmax = max(rmax,x)
        r=1
        ymin = min(ymin,y)
        ymax = max(ymax,y)
        yy=1

def lpos(t):
    ans = inf
    if xx: ans = min(ans,xmin)
    if l: ans = min(ans,lmin+t)
    if r: ans = min(ans,rmin-t)
    return ans
def rpos(t):
    ans = -inf
    if xx: ans = max(ans,xmax)
    if l: ans = max(ans,lmax+t)
    if r: ans = max(ans,rmax-t)
    return ans

def dpos(t):
    ans = inf
    if yy: ans = min(ans,ymin)
    if l: ans = min(ans,umin+t)
    if r: ans = min(ans,dmin-t)
    return ans
def upos(t):
    ans = -inf
    if yy: ans = max(ans,ymax)
    if u: ans = max(ans,umax+t)
    if d: ans = max(ans,dmax-t)
    return ans

s = {0}
if xx and l:
    if lmin - xmin > 0: s.add(lmin - xmin)
    if lmax - xmax > 0: s.add(lmax - xmax)
if xx and r:
    if xmin - rmin > 0: s.add(xmin - rmin)
    if xmax - rmax > 0: s.add(xmax - rmax)
if l and r:
    if lmin-rmin > 0: s.add((lmin-rmin)/2)
    if lmax-rmax > 0: s.add((lmax-rmax)/2)

if yy and d:
    if dmin - ymin > 0: s.add(dmin - ymin)
    if dmax - ymax > 0: s.add(dmax - ymax)
if yy and u:
    if ymin - umin > 0: s.add(ymin - umin)
    if ymax - umax > 0: s.add(ymax - umax)
if d and u:
    if dmin-umin > 0: s.add((dmin-umin)/2)
    if dmax-umax > 0: s.add((dmax-umax)/2)
    
#print(rmax,xmax)

ans = 10**18
for t in s:
#    print(rpos(t),lpos(t),dpos(t),upos(t),xmin,ymin,xmax,ymax,xx,yy)
    area = (rpos(t)-lpos(t))*(upos(t)-dpos(t))
#    print(t,area)
    if area < ans:
        ans = area

print(ans)
    










