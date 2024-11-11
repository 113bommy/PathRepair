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
  if l>=r:x+=[[k,l,r]]
  else:y+=[[n-k,r,l]]
 for x in x,y:
  x.sort();h=[]
  for k,l,r in x:
   if k>0:s+=l;heappush(h,l-r)
   else:s+=r
   if len(h)>k:s+=heappop(h)
 print(s)