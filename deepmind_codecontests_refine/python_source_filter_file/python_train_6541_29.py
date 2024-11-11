n,C=map(int,input().split())
import collections
d=collections.defaultdict(list)
for i in range(n):
    s,t,c=map(int,input().split())
    d[c].append((s,t))
T=[0 for i in range(2*10**5+1)]
for i in d.values():
    i.sort()
    T[i[0][0]*2-1]+=1
    T[i[-1][1]*2+1]-=1
    for x,y in zip(i,i[1:]):
        s1,t1=x
        s2,t2=y
        if t1!=s2:
            T[s2*2-1]+=1
            T[t1*2+1]-=1
from itertools import accumulate
T=list(accumulate(T))
print(max(T))