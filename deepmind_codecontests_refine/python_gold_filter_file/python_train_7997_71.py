x, y = map(int,input().split())
if y != 1:
  if x*(y-1)%y != 0:
    print(x*(y-1))
  else:
    print(-1)
else:
  print(-1)