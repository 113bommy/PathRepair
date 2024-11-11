import bisect
from collections import defaultdict

S=list(input().strip())
T=list(input().strip())
L=len(S)

if set(T)>set(S):
  print(-1)
  exit()

d=defaultdict(list)
for i,s in enumerate(S):
  d[s].append(i)
start=-1
ans=0
for i in T:
  p=bisect.bisect_right(d[i],start)
  le=len(d[i])
  if p==le:
    ans+=(L-start-1)+(d[i][0]+1)
    start=d[i][0]    
  else:
    ans+=d[i][p]-start
    start=d[i][p]
print(ans)