n,l,a=map(int,input().split())
res=0
if n>0:
    t1,l1=map(int,input().split())
    res+=max(0,(t1-1)//a)
from sys import stdin
for i in range(n-1):
    t2,l2=map(int,stdin.readline().split())
    res+=(t2-t1-l1)//a
    t1,l1=t2,l2
if n>0:res+=(l-t1-l1)//a
else:res=l//a
print(res)