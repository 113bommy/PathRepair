x,k,d=map(int,input().split())

x=abs(x)
ans=0
if x/d>k:
  ans=x-k*d
else:
  e= x/d
  k-=e
  x-=e*d
  if k%2==1:
    x=abs(x-d)
  ans=x

print(ans)