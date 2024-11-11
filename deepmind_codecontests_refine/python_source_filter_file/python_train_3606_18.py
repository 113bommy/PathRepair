from pprint import pprint as pp
def GI(): return int(input())
def GIS(): return map(int, input().split())

from math import sqrt, floor

def main():
  GI()
  m = -1
  for x in GIS():
    if x < 0:
      m = max(x, m)
    else:
      s = sqrt(x)
      if s != floor(s):
        m = max(x, m)
  print(m)

main()
