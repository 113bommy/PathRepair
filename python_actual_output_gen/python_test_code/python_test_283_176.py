x,a,b = map(int,input().split())

if b > a+x:
  print("dangerou")
elif b > a:
  print("safe")
else:
  print("delicious")