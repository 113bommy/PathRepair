####################
####################
####################
####################
from heapq import*
i=input
for s in[0]*int(i()):
 n,x,*y=int(i()),[]
 for _ in'_'*n:
  k,l,r=map(int,i().split())
  if l>=r:s+=r;x+=[[n,l-r]]
  else:s+=l;y+=[[n-k,r-l]]*(k<n)
 for x in x,y:
  x.sort();h=[]
  for k,d in x:
   heappush(h,d)
   if len(h)>k:heappop(h)
  for d in h:s+=d
 print(s)