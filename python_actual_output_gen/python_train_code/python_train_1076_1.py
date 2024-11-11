a,b,c=map(int,input().split())
if 4*b*c<(c-a-b)**2 and c-a-b>0:
  print("Yes")
else:
  print("No")
