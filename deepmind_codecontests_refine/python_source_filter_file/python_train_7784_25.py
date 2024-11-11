n,m=map(int,input().split())
if n%2==1:
  for i in range(m):
    print(str(i+1)+" ",str(n-i))
else:
  k=n//4
  for i in range(m):
    if i<=k:
      print(str(i+1),str(n-i))
    else:
      print(str(i+2),str(n-i))
      