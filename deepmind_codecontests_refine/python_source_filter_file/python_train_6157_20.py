from sys import stdin, stdout
from collections import Counter
nmbr = lambda : int(input())
lst = lambda : list(map(int, input().split()))
def fn(days):
    times=days//n
    l=times*d['L']
    r=times*d['R']
    u=times*d['U']
    down=times*d['D']
    for i in range(days%n):
        if s[i]=='L':l+=1
        elif s[i]=='R':r+=1
        elif s[i]=='D':down+=1
        else:u+=1
    # print(l,r,u,down)
    dxx=dx-(r-l)
    dyy=dy-(u-down)
    # print(dx,dy,dxx,dyy)
    return (abs(dxx)+abs(dyy)<=days)


for _ in range(1):#nmbr()):
    x1,y1=lst()
    x2,y2=lst()
    n=nmbr()
    dx=x2-x1
    dy=y2-y1
    s=input()
    d=Counter(s)
    # fn(1)
    # break
    l,r=1, 10**10
    while l<=r:
        mid=(l+r)>>1
        if fn(mid)==False:l=mid+1
        else:r=mid-1
    if fn(l):print(l)
    else:print(-1)