a,b,c=map(int,input().split())
if b<=c:
  print("delicious")
elif b<=a+c:
  print("safe")
else:
  print("dangerous")