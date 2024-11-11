x,a,b=map(int,input().split())
if b-a>=0:
  print("delicious")
elif -x<=b-a<0:
  print("safe")
else:
  print("dangerous")