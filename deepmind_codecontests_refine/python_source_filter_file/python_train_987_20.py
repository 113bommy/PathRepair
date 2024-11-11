# import sys
# input=sys.stdin.readline
from bisect import bisect_right as bi

n,d=list(map(int,input().split()))
a=[]
for i in range(n):
    a.append(list(map(int,input().split())))
a.sort()
b=[]
c=[0]
s=0
for i in range(n):
    b.append(a[i][0])
    s+=a[i][1]
    c.append(s)
c.append(s)
f=[]
for i in range(n):
    e=bi(b,b[i]+d)
    g=c[e]-c[i]
    f.append(g)
print(max(f))