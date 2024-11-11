a,b,c=map(int,input().split())
if d>c:
  print("delicious")
elif abs(b-c)>a:
  print("dangerous")
else:
  print("safe")