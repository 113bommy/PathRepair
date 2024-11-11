from collections import defaultdict
import bisect
import sys
s=input()
t=input()

d=defaultdict(list)

ls=len(s)
lt=len(t)

for i in range(ls):
    d[s[i]].append(i)

buf=-1
l=0
for i in range(lt):
    if not d[t[i]]:
        print(-1)
        sys.exit()
    idx=bisect.bisect_right(d[t[i]],buf)
    if idx>=len(d[t[i]]):
        buf=d[t[i]][0]
        l+=1
    else:
        buf=d[t[i]][idx]
print(l*ls+buf+1)