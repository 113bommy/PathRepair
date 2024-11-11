from collections import*
from bisect import*

s=input()
t=input()
slen=len(s)
d=defaultdict(list)

for i,c in enumerate(s):
    d[c].append(i)

nowplace=-1
roop=0
for c in t:
    if not d[c]:
        print(-1)
        exit()
    i=bisect(d[c],nowplace)
    if len(d[c])==i:
        roop+=1
        nowplace=d[c][0]
    else:
        nowplace=d[c][i]

print(roop*slen+nowplace+1)
