from math import pi
def get_volumn(d, h):
  return (pi * d**2 * h) / 4

def get_height(v, d):
  return (4 * v) / pi * d**2

d, h, v, gh = [int(i) for i in input().split()]
dh = get_height(v, d)
init_v = get_volumn(d, h)
if gh >= dh:
  print("NO")
else:
  dec_h = dh - gh
  dec_v = get_volumn(d, dec_h)
  print("YES")
  print("{:0.12f}".format(init_v / dec_v))