a,b,c,d=map(int,input().split())
n=a+b
m=c+d
if n>m:
  print("Left")
elif m>n:
  print("Right")
else:
  print("Balanced")