import sys, math

#f = open('input/input_0', 'r')
f = sys.stdin

R, x1, y1, x2, y2 = map(int, f.readline().split())

dx = x1 - x2
dy = y1 - y2
if dx**2 + dy**2 >= R**2:
  print(x1, y1, R)
if dx == 0 and dy == 0:
  print(x1+R/2, y1, R/2)
else:
  dl = (dx**2 + dy**2) ** 0.5
  r = (dl + R) / 2
  ax = x2 + dx / dl * r
  ay = y2 + dy / dl * r
  print(ax, ay, r)
