import math

n = int(input())
for i in range(n // 2, 1, -1):
  if math.gcd(i, n - i) == 1:
    print(i,n - i)
    break