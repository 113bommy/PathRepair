import math
n = int(input())
for a in range(int(math.sqrt(n)) + 1, 0, -1):
  if n % a == 0:
    break
print(a, n // a)