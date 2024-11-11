a,b,c,d=map(int,input().split())
e=a+b
f=c+d
if e>f:
  print("Left")
elif e=f:
  print("Balanced")
else:
  print("Right")