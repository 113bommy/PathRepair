x=list(map(int,input().split()))
if x[0]<x[1] :
  print("-1")
else :
  if x[0]%2==0 :
    s = x[0]%2
  else :
    s = x[0]%2 + 1 
  while s%x[1]!=0 :
    s += 1
  print(s)
