from fractions import gcd
from functools import reduce

def gcdd(*numbers):
    return reduce(gcd, numbers)

n, k = map(int,input().split())
a = list(map(int,input().split()))

agcd = gcdd(*a)

if max(a) > k and k%agcd ==0:
  print('POSSIBLE')
else:
  print('IMPOSSIBLE')