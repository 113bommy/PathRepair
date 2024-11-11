import math
n = int(input())
x1, y1, x2, y2 = map(int, input().split())
t1 = 0
t2 = math.inf

yes = True
for i in range(n):
  x, y, vx, vy = map(int, input().split()) 
  if vx == 0:
    if x <= x1 or x >= x2:
      yes = False
      break
  else:
    tt1 = (x1-x)/vx
    tt2 = (x2-x)/vx
    tt1, tt2 = min(tt1, tt2), max(tt1, tt2)
    t1 = max(t1, tt1)
    t2 = min(t2, tt2)
  if vy == 0:
    if y <= y1 or y >= y2:
      yes = False
      break
  else:
    tt1 = (y1-y)/vy
    tt2 = (y2-y)/vy
    tt1, tt2 = min(tt1, tt2), max(tt1, tt2)
    t1 = max(t1, tt1)
    t2 = min(t2, tt2)
    
if yes and t1 <= t2:
  print(t1)
else:
  print(-1)  
      
