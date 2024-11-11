a,b,c=input().split()
if a >= c:
  print(a-c,b)
else:
  print(0,max(a+b-c,0))