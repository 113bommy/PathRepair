import math
k = int(input())
n = 0
for a in range(1,k+1):
  for b in range(1,k+1):
    for c in range(1,k+1):
      n += math.gcd(math.gcd(a, b),c)
print(n)