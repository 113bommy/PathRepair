import sys
input=sys.stdin.readline
n,sx,sy=map(int,input().split())
L=[0,0,0,0]
for i in ' '*n:
    a,b=map(int,input().split())
    if a-sx>0:L[0]+=1
    if a-sx<0:L[1]+=1
    if a-sy>0:L[2]+=1
    if a-sy<0:L[3]+=1
m=0
mval=0
for i in range(4):
    if L[i]>mval:
        m=i
        mval=L[i]
print(mval)
dir=[[1,0],[-1,0],[0,1],[0,-1]]
print(sx+dir[m][0],sy+dir[m][1])