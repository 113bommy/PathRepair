n=int(input())
la=list(map(int,input().split()))
lb=list(map(int,input().split()))
limit=0
must=0
for i in range(n):
  if la[i]>lb[i]:
    must+=la[i]-lb[i]
  elif la[i]==lb[i]:
    pass
  else:
    limit=(lb[i]-la[i])//2
if limit*2<must:
  print("No")
else:
  print("Yes")