x,y = map(int,input().split()) 
if x == 1 or y == 1:
  print(0)
else:
  print(-(-(x*y)//2))