import math
import fractions
from functools import reduce

n, m = map(int, input().split())
a = list(map(lambda x:int(x)//2, input().split()))

t = 0
while all([i%(2**(t+1))==0 for i in a]):t+=1
a = [i//(2**t) for i in a]

if any([i%2==0 for i in a]):
  print(0)
else:
  b = reduce(lambda x,y:x*(y//fractions.gcd(x,y)),a)
  print((m//b+1)//2)