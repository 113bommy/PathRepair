from math import gcd

k = int(input())
ans = 0

for a in range(k+1):
  for b in range(k+1):
    for c in range(k+1):
      ans += gcd(gcd(a,b),c)

print(ans)