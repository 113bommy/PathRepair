a,b,c,d=map(int,input().split())
if abs(a-c)<=d | (abs(a-b)<=d & abs(b-c)<=d):
  print("Yes")
else:
  print("No")