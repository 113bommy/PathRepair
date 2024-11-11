a,b,c,d=map(int,input().split())
l=a+b
r=c+d
if l < r:
  print("Right")
elif l==r:
  print("Balanceed")
else:
  print("Left")
