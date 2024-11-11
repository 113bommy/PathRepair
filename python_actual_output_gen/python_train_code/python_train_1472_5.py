n=int(input())
if n%2==1:
  print(0)
else:
  c=0
  x=5
  while x<=n:
    c+=n//x
    x*=5
  print(c)