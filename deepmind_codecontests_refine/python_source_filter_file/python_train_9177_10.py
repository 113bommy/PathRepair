from collections import *
n=int(input())
l=list(map(int,input().split()))
for i in range(n):
    l[i]=min(l[i],-l[i]-1)
if(n%2==1):
    x=l.index(max(l))
    l[x]=-l[x]-1
print(*l)