####################
####################
####################
####################
from heapq import*
i=input
for s in[0]*int(i()):
 n,x,*y=int(i()),[]
 for _ in'_'*n:k,l,r=t=[*map(int,i().split())];x+=[t]*(l>r);y+=[[n-k,r,l]]*(l<=r)
 for x in x,y:
  x.sort();h=[]
  for k,l,r in x:
   if k>0:s+=l;heappush(h,r-l)
   else:s+=r
   if len(h)>k:s+=heappop(h)
 print(s)