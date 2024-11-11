x,a,b=map(int, input().split())

if b<=a:
  print("delicious")
elif a+x>b:
  print("safe")
else:
  print("dangerous")