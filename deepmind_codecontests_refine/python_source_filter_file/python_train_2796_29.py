n,x=map(int,input().split())
if x==1 or x==2*n-1:
  print("No")
else:
  print("Yes")
  if x>n:
    for i in range(1,x-n+1):
      print(i)
    for i in range(3*n-x-1):
      print(2*n-1-i)
  elif x==n:
    for i in range(1,2*n):
      print(i)
  else:
    for i in range(n-x+1):
      print(2*n-1-i)
    for i in range(n+x-2):
      print(i+1)