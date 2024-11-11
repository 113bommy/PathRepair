mod=10**9+7
import math
n=int(input())
ans=1
l=[0]*n
for ii in range(2,n+1):
  i=ii
  for j in range(2,int(math.sqrt(i))+1):
    if i%j==0:
      cnt=0
      while  i%j==0:
        cnt+=1;i//=j
      l[i-1]+=cnt
  if i!=1:
    l[i-1]+=1
for i in l:
  ans*=(i+1)
  ans%=mod
print(ans)
