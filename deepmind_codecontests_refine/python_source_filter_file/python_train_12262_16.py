import math

K = int(input())
c = 0
for i in range(1,K+1):
  for j in range(1,K+1):
    for k in range(1,K+1):
      c += math.gcd(math.gcd(i,j),k)
print(c)
      
