# cook your dish here
from collections import defaultdict as dt
f=0                
n,m=map(int,input().split())
d=dt(lambda:[])
e=dt(lambda:0)
c=dt(lambda:0)
a={}
j=1
for i in list(map(int,input().split())):
    if i:
        a[j]=1
    else:
        a[j]=0
    j=j+1
for _ in range(n-1):
    u,v=map(int,input().split())
    d[u].append(v)
    d[v].append(u)
q=[1]
if a[1]==1:
    c[1]=1
    e[1]=1
while q:
    x=q[0]
    q.pop(0)
    z=0
    for i in d[x]:
        if e[i]==0:
            z=1
            e[i]=1
            if a[i]==1:
                c[i]=c[x]+1
            else:
                if c[x]>m:
                    c[i]=c[x]
                else:
                    c[i]=0
            q.append(i)
    if z==0 and c[x]<=m:
        f=f+1
print(f)