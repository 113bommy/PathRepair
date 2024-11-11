a,b,c,d=map(int,input().split())
if abs(b-a)<=d or abs(c-b)<=d 0r abs(a-c)<=d:
  print("Yes")
else:
  print("No")