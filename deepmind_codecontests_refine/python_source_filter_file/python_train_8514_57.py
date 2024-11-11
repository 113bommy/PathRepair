from collections import*
from bisect import*
s=input()
n=len(s)
t=input()
d=defaultdict(list)
for i,c in enumerate(s):
    d[c].append(i)
m=o=0
for c in t:
    if not d[c]:
        print(-1)
        exit()
    i=bisect(d[c],m)
    if len(d[c])==i:
        o+=1
        m=d[c][0]
    else:
        m=d[c][i]
print(o*n+m+1)