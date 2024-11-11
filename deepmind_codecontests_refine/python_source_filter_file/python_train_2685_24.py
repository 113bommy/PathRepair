N,M=map(int,input().split())
a=list(map(int,input().split()))

import fractions
from functools import reduce

def lcm_base(x, y):
    return (x * y) // fractions.gcd(x, y)

def lcm_list(numbers):
    return reduce(lcm_base, numbers, 1)

l=lcm_list(a)

for s,t in enumerate(a):
    if l%t==0:
      print("0")
      exit()

print((2*M//l+1)//2)
