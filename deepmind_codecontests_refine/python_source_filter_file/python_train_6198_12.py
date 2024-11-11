from math import gcd
from functools import reduce

N = int(input())
M = list(map(int, input().split(' ')))
R = list(map(int, input().split(' ')))
n = reduce(lambda x, y: x*y//gcd(x, y), M, 1)
tot = 0
print(n)
for i in range(n):
  for j in range(N):
    if (i-R[j]) % M[j] == 0:
      tot = tot+1
      break
print(tot/n)
