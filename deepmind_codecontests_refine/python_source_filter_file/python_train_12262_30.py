import math
n = int(input())
ans = 0
for i in range(1,n):
  for j in range(1, n):
    for k in range(1, n):
      ans += math.gcd(i, math.gcd(j, k))
print(ans)