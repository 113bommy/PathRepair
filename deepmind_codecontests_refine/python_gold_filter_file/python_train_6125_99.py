a,b,c,d=map(int,input().split())
a+=b
c+=d
if a>c:
  print("Left")
elif a<c:
  print("Right")
else:
  print("Balanced")