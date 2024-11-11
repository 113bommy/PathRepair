N=int(input())
ans=0
for n in range(1,N+1):
  _ans=0
  for x in range(1,n+1):
    if n%x==0:
      _ans+=1
  if _ans==8:
    ans+=1
print(ans)