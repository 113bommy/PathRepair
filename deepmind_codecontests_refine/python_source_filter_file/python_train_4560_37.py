n,k=map(int,input().split())
a=list(map(int,input().split()))
f=list(map(int,input().split()))

a=sorted(a)[::-1]
f=sorted(f)

ok=(10**6)*n
ng=-1

import math
def isOK(val,arr,farr,k):
  s=0
  for i in range(len(arr)):
    s+=max(math.ceil(a[i]-val/f[i]),0)
  return s<=k
  
while abs(ok-ng)>1:
  mid=abs(ok+ng)//2
  if isOK(mid,a,f,k):
    ok=mid
  else:
    ng=mid
    
print(ok)
