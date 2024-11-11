import math
import collections
l=list(input())
n=len(l)
l1=[0]*n
d={}
for i in range(n):
    if(l[i] not in d):
        if(i==0):
            d[l[i]]=[i]
        else:
            d[l[i]]=[-1,i]
    else:
        d[l[i]].append(i)
for i in d:
    if(d[i][-1]!=n-1):
        d[i].append(n)
m=n
d=collections.OrderedDict(sorted(d.items()))
for i in d:
    d1=0
    for j in range(len(d[i])-1):
        d1=max(d1,d[i][j+1]-d[i][j])
    for j in range(d1-1,m):
        l1[j]=i
    m=min(m,d1-1)
print(max(1,m+1))