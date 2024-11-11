a,b,c=map(int,input().split())
if b-c>a:
  print("dangerous")
elif b>c:
  print("safe")
else:
  print("delicious")