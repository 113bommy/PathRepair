x,y = (int(i) for i in input().split())
if x== y or y == 1:
  print(-1)
  exit()
else:
  print(x*(y-1))