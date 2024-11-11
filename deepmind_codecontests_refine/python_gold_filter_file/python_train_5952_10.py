from collections import defaultdict as dd
from sys import stdin, stdout
I=stdin.readline
P=stdout.write
for _ in range(int(I())):
    n=int(I())
    a=[int(i) for i in I().split()]
    d=dd(int)
    for i in a: d[i]+=1
    d=sorted(d.values(),reverse=1)
    l,c=[],0
    for i in d:
        if l==[]:
            l+=[i]
            c+=i
        else:
            if l[-1]<=0: continue
            c+=min(l[-1]-1,i)
            l+=[min(l[-1]-1,i)]
    P(str(c)+'\n')
