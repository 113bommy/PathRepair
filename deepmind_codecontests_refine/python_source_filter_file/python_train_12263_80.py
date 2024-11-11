import math
n = int(input())
x = math.ceil(n / 1.08)
if x * 1.08 == n:
  print(x)
else:
  print(":(")