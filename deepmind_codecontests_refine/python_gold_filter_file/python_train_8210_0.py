import math

class Ufo:
  def __init__(self, x, y, r, v):
    self.dist = get_dist(x, y)
    self.angle = get_angle(y, x)
    self.rad = r
    self.v = v

def get_dist(x, y):
  return (x ** 2 + y ** 2) ** (1 / 2)

def get_angle(x, y):
  angle = math.atan2(y, x)
  if angle < 0:
    angle += math.pi * 2
  return angle

def reach(ufos, R):
  remove_lst = []
  for ufo in ufos:
    ufo.dist -= ufo.v
    if ufo.dist <= R:
      remove_lst.append(ufo)
  for ufo in remove_lst:
    ufos.remove(ufo)
  return len(remove_lst)

def is_dead(ufo, laser, R):
  diff = abs(ufo.angle - laser)
  if diff > math.pi:
    diff = math.pi * 2 - diff
  if (diff <= math.pi / 2 and ufo.dist * math.sin(diff) <= ufo.rad) or (ufo.dist <= ufo.rad):
    if ufo.dist * math.cos(diff) + (ufo.rad ** 2 - (ufo.dist * math.sin(diff)) ** 2) ** (1 / 2) > R:
      return True
  return False

def shoot(ufos, laser, R):
  remove_lst = []
  for ufo in ufos:
    if is_dead(ufo, laser, R):
      remove_lst.append(ufo)
  for ufo in remove_lst:
    ufos.remove(ufo)

def main():
  while True:
    R, n = map(int, input().split())
    if R == 0:
      break
  
    ufos = []
    for _ in range(n):
      x, y, r, v = map(int, input().split())
      ufos.append(Ufo(x, y, r, v))
    
    ans = 0
    while ufos:
      ans += reach(ufos, R)
      if ufos:
        laser = min(ufos, key=lambda ufo:ufo.dist).angle
        shoot(ufos, laser, R)
    print(ans)
main()
