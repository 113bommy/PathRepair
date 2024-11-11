n=int(input())
import copy
a= [int(x) for x in input().split()]
MAX_A = 10 ** 6 + 1
histogram = [0] * MAX_A
for x in a:
  histogram[int(x)] = 1
for divider in range(2, MAX_A):
  count = 0
  for counted in histogram[divider::divider]:
    count += counted
  if count > 1:
    break
else:
  print('pairwise coprime')
  exit()
from math import gcd
g=gcd(a[0],a[1])
if n==2:
  print('setwise coprime' if g==1 else 'not coprime')
  exit()
for i in range(2,n):
  g=gcd(g,a[i])
if g==1:
  print('setwise coprime')
else:
  print('not coprime')
