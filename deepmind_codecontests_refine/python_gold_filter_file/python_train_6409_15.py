n,m,k=map(int,input().split())
X,S=map(int,input().split())
a=[X]+[*map(int,input().split())]
b=[0]+[*map(int,input().split())]
c=[0]+[*map(int,input().split())]
d=[0]+[*map(int,input().split())]
from bisect import bisect as bis
result=100000000000000000000
for x,y in zip(a,b):
    s=S-y
    item=bis(d,s)
    res=n*X
    if item==0:
        if d[0]<=s:res=max(0,n-c[0])*x
    else:
        item-=1
        if d[item]<=s:res=max(0,n-c[item])*x
    result=min(res,result)
print(result)