import math
K = int(input())
m = 0
for i in range(1, K+1):
  for j in range(1, K+1):
    for k in range(1, K+1):
      m += math.gcd(math.gcd(i, j), k)
print(m)