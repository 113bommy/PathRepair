import sys
input = sys.stdin.readline
q=int(input())
n=0
x,y=0,0
f1,f2,f3,f4=0,0,0,0
tx,ty=0,0
mnx,mxx,mny,mxy=0,0,0,0
for i in range(q):
    n=int(input())
    mnx=-100000
    mxx=10000
    mny=-100000
    mxy=100000
    for j in range(n):
        x,y,f1,f2,f3,f4=map(int,input().split())
        if(f1==0):
            mnx=max(mnx,x)
        if(f2==0):
            mxy=min(mxy,y)
        if(f3==0):
            mxx=min(mxx,x)
        if(f4==0):
            mny=max(mny,y)
    if(mnx<=mxx and mny<=mxy):
        print(1,mnx,mny)
    else:
        print(0)