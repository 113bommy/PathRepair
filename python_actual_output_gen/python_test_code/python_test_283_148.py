x,a,b=map(int,input().split())
if b<=a:
  print('delicious')
elif b<=x:
  print("safe")
else:
  print("dangerous")