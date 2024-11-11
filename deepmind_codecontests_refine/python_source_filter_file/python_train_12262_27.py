import math
k = int(input())
ans = 0
for i in range(1,k+1):
  for j in range(1,k+1):
    for m in range(1,k+1):
      ans += math.gcd(math.gcd(i,j),m)
print(ans)