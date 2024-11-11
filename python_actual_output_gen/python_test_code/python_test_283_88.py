x,a,b=map(int,input().split())
if a > b:
  print("delicious")
elif x >= b-a:
  print("safe")
else:
  print("dangerous")