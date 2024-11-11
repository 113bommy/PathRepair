n,k=map(int,input().split())
if n==1 or k==1:
  if n==1 and k==1:
    print("Yes")
  elif n==1:
    if k>2:
      print("Yes")
    else:
      print("No")
  else:  
    print("Yes")
elif k>=n:
  print("No")
else:
  i=1
  while i<=k and n%i==i-1:
    i+=1 
  if i==k+1:
    print("Yes")
  else:
    print("No")