x,a,b=map(int,input().split())
if a<=b:
  print("delicious")
elif a<=b+x:
  print("safe")
else:
  print("dangerous")