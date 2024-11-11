a,b,c,d=map(int,input().split())
e=max(a,b)
f=min(c,d)
if e<f:
  print(f-e)
else:
  print(0)