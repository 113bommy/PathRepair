from collections import*
from heapq import*
n,m,*a=map(int,open(0).read().split())
t=[-1]*n
def r(x):
  while~t[x]:x=t[x]
  return x
def u(x,y):
  x,y=r(x),r(y)
  if x!=y:
    if t[x]>t[y]:x,y=y,x
    t[x]+=t[y]
    t[y]=x
d=defaultdict(list)
for x,y in zip(*[iter(a[n:])]*2):u(x,y)
for i,v in enumerate(a[:n]):d[r(i)]+=v,
if len(d)<2:
  print(0)
  exit()
*d,=map(sorted,d.values())
c=sum(heappop(t)for t in d)
l=[]
for t in d:l+=t
i=len(d)-2
print(i>len(l)and'Impossible'or c+sum(sorted(l)[:i]))