from math import*
from bisect import*
n,*t=map(int,open(0).read().split())
m=int(log2(n))+1
x=t[:n]
l=t[n]
d=[[bisect(x,y+l)-1for y in x]]+[[0]*n for _ in range(m)]
for i in range(m):
    for j in range(n):
        d[i+1][j]=d[i][d[i][j]]
print(d)
for a,b in zip(t[n+2::2],t[n+3::2]):
    a-=1
    b-=1
    if b<a:a,b=b,a
    c=1
    for i in range(m,-1,-1):
        if d[i][a]<b:
            a=d[i][a]
            c+=2**i
    print(c)