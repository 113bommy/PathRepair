# 04.77 sec -> Time Limit Exceeded?
import sys
import math

# Sieve of Eratosthenes
N = 50000
searchList = list(range(3, N + 1, 2))
primes = [2]
while True:
  top = searchList.pop(0)
  primes.append(top)
  if top > math.sqrt(N):
    break
  searchList = [s for s in searchList if s % top != 0]
primes.extend(searchList)


for line in sys.stdin:
  try:
    n = int(line)
    pre = 2
    for p in primes:
      if p < n:
        pre = p
      if p > n:
        print(pre, p)
        break
  except:
    break