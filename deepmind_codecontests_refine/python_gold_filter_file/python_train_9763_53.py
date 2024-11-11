a,b,c,d=map(int,input().split())
if a+1+b>d:
  print(min(a,d))
else:
  print(a-(d-a-b))
  