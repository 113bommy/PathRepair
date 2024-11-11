W, H, N = map(int,input().split())
dx, dy = 0, 0

for i in range(N):
  x, y, a = map(int,input().split())
  if(a == 1):
    dx = max(dx, x)
  elif(a == 2):
    W = min(W, x)
  elif(a == 3):
    dy = max(dy, y)
  else:
    H = min(H, y)
if(dx <= W or dy <= H):
  print(0)
else:
  print((dx-W) * (dy-H))
