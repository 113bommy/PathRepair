from itertools import accumulate as ac
n=int(input())
a,b=[],[]
for i in range(n):
    x,s=map(int,input().split())
    a.append(x)
    b.append(s)
r=[0]+list(ac(b))
l=b[:]
for i in range(n):
    r[i]+=-a[i]
    l[i+1]+=-a[i]
q,d=0,0
for i in range(1,n+1):
    d=max(l[i]-q,d)
    q=min(q,r[i-1])
print(d)