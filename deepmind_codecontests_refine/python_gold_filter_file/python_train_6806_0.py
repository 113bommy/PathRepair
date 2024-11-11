from math import *
import functools
input()
numbs = [int(s) for s in input().split()]

def getMaxPot2(x):
  res = 1
  while(2*res <= x):
    res*=2
  return res
  
a = functools.reduce(lambda x, y: x&y, numbs)
numbs = [a^s for s in numbs]
maxPot2 = getMaxPot2(max(numbs))

res = 0
for i, val in enumerate(numbs):
  if (val & maxPot2) > 0:
    max2, j = -1, i-1
    while(j>=0 and (numbs[j] & maxPot2) == 0 ):
      if numbs[j] > max2:
        max2 = numbs[j]
        res = max(res, val ^ max2)
      j-=1
    max2, j = -1, i+1
    while(j<len(numbs) and (numbs[j] & maxPot2) == 0 ):
      if numbs[j] > max2:
        max2 = numbs[j]
        res = max(res, val ^ max2)
      j+=1
      
print(res)