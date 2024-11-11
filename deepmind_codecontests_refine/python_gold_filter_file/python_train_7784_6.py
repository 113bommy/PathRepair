n,m=map(int,input().split())
if n%2==1:
  for i in range(1,m+1):
    print(i,n-i)
else:
  if m>n//4:
    for i in range(1,n//4+1):
      print(i,n-i+1)
    for i in range(1,m-n//4+1):
      print(n//2-i,n//2+i)
  else:
    for i in range(1,m+1):
      print(i,n-i+1)