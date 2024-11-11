import math
K = int(input())
s = 0
for a in range(1,K+1):
  for b in range(1,K+1):
    x = math.gcd(a,b)
    for c in range(1,K+1):
      s += gcd(x,c)
print(s)