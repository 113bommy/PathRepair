import itertools  
import math
p=int(input())
aa=p
for i in range(1,11):
 t=list(itertools.combinations([2,3,5,7],i))
 for j in t:
  ans=1
  for k in j:
   ans*=k
  ans=int(p/ans)
  if i&1:
   aa-=ans
  else:
   aa+=ans
print(aa)
