import math
from sys import stdin

cases = int(stdin.readline().strip())

for _ in range(cases):
  n, x, a, b = [int(x) for x in stdin.readline().strip().split(" ")]


  if (max(a, b) + x) / n > 1:
    new_b = n
    extra = (max(a, b) + x) % n
    new_a = 1 if min(a, b) - extra < 1 else min(a, b) - extra
  else: 
    new_b = max(a, b) + x
    new_a = min(a, b)

  print(new_b - new_a)
