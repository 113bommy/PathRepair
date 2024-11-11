k=int(input())+1
from math import gcd
print(sum(gcd(gcd(i,j),r) for i in range(1,k)   for j in range(1,k)  for r in range(1,k) )
