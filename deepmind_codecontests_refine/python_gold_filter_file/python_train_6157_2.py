import sys
import math
from collections import defaultdict
def possible(days,X,Y,n,x2,y2,x1,y1):
    stx,sty=(X[-1]*(days//n)),(Y[-1]*(days//n))
    #print(stx,'stx',sty,'sty')
    a=int((days)%n)
    #print(days,'DAYS',n,'n',a,'a')
    addx,addy=X[a],Y[a]
    newx,newy=stx+addx,sty+addy
    #print(newx,'newx',newy,'newy')
    shipx,shipy=x2-(x1+newx),y2-(y1+newy)
    #print(shipx,'shipx',shipy,'shipy')
    if abs(shipx)+abs(shipy)<=days:
        return True
    return False
x1,y1=map(int,sys.stdin.readline().split())
x2,y2=map(int,sys.stdin.readline().split())
n=int(sys.stdin.readline())
s=sys.stdin.readline()[:-1]
xw,yw=0,0
xwind,ywind=[0 for _ in range(n+1)],[0 for _ in range(n+1)]
delx,dely=x2-x1,y2-y1
for i in range(n):
    if s[i]=='U':
        yw+=1
    if s[i]=='D':
        yw-=1
    if s[i]=='L':
        xw-=1
    if s[i]=='R':
        xw+=1
    xwind[i+1]=xw
    ywind[i+1]=yw
#print(xwind,'xwind')
#print(ywind,'ywind')
#print(delx,'delx',dely,'dely')
low,high=0,1e15
ans=1e20
while low<=high:
    mid=(low+high)//2
    if possible(mid,xwind,ywind,n,x2,y2,x1,y1):
        ans=min(ans,mid)
        high=mid-1
    else:
        low=mid+1
if ans==1e20:
    print(-1)
else:
    print(int(ans))
