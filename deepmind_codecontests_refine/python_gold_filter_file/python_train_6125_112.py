a,b,c,d=map(int,input().split())

m=a+b
n=c+d

if m>n:
  print("Left")
elif m==n:
  print("Balanced")
else:
  print("Right")