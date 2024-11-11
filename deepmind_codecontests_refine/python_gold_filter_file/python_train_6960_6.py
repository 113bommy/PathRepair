w,h,n = map(int,input().split())
lx,hx,ly,hy = 0,w,0,h
for i in range(n):
  x,y,a = map(int,input().split())
  if a == 1:
    lx = max(lx, x)
  elif a == 2:
    hx = min(hx, x)
  elif a == 3:
    ly = max(ly, y)
  elif a == 4:
    hy = min(hy, y)
print(max(0, hx-lx) * max(0, hy-ly))