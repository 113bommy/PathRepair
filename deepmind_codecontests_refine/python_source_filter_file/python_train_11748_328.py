a,b,c=map(int,input().split())
if b>c:
  print("delicious")
elif a+b >c:
  print("safe")
else:
  print("dangerous")