n, x, y =map(int, input().split())
p = []
dx, dy = 0, 0
for i in range (n):
  x1, y1 = map(int, input().split())
  dx, dy = x1 - x, y1 - y
  if (dx == 0):
    if ('a' not in p): 
      p.append('a')
  elif dy/dx not in p:
    p.append(dy/dx)
print(len(p))