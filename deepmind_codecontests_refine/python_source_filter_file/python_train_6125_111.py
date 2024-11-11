a,b,c,d=map(int,input().split())

m=a+b
n=c+d

if m>n:
  print("left")
elif m==n:
  print("balanced")
else:
  print("left")