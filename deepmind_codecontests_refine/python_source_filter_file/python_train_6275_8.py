from math import ceil
for _ in range(int(input())):
  n = int(input())
  print(ceil((n ** 0.5 - 0.01) * 2) - 2)