a,b,c,d=map(int,input().split())
e=max(a,c)
f=min(b,d)
if e<f:
  print(f-e)
else:
  print(0)