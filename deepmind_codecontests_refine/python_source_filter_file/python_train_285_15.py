from heapq import*
i=input
for s in[0]*int(i()):
 n,x,*y=int(i()),[]
 for _ in'_'*n:k,l,r=t=[*map(int,i().split())];x+=[t]*(l>r);y+=[[n-k,r,l]]*(l<=r)
 for x in x,y:
  x.sort();m=len(x);h=[(0,0)]*n
  while h:
   while[[m]]<x[-1:]:k,l,r=x.pop();heappush(h,(r-l,l,r))
   s+=heappop(h)[~(m>0)];m-=1
 print(s)