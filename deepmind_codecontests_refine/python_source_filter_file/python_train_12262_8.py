import math
n = int(input())
res = 0
for i in range(1,n):
  for j in range(1,n):
    for k in range(1,n):
      res += math.gcd(math.gcd(i,j),k)
print(res)