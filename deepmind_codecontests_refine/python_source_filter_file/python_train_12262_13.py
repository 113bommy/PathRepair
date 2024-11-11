import math

K=int(input())
res=0
for i in range(1,K+1):
  for j in range(1,K+1):
    for k in range(1,K+1):
      res+=math.gcd(i,math.gcd(j,k))
print(res)