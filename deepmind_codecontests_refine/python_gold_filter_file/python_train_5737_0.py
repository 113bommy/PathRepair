import sys
import collections as cc
I=lambda:list(map(int,input().split()))
n,=I()
a=[]
b=[]
c=[]
d=[]
for i in range(n):
    x,y=I()
    a.append(x)
    b.append(y)
    c.append(x)
    d.append(y)
a.sort()
b.sort()
ans=0
for i in range(n):
    nl=a[-1]
    nr=b[0]
    if a[-1]==c[i]:
        nl=a[-2]
    if b[0]==d[i]:
        nr=b[1]
    ans=max(ans,nr-nl)
print(ans)