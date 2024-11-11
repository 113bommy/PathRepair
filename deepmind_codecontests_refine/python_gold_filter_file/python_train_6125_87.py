a,b,c,d=map(int,input().split())
if a+b<c+d:
  print("Right")
elif a+b>c+d:
  print("Left")
else:
  print("Balanced")