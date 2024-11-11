a,b,c,d = map(int,input().split())
if abs(a-c) or (abs(a-b)<=d and abs(b-c)<=d):
  print("Yes")
else:
  print("No")