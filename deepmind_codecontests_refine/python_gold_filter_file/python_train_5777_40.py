n=int(input())
if n==1:
  print(1)
  print(n)
elif n==2:
  print(1)
  print(1)
elif n==3:
  print(2)
  print(1,3)
else:
  print(n)
  for i in range(2,n+1,2):
    print(i)
  for i in range(1,n+1,2):
    print(i)